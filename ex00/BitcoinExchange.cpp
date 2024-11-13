#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

Bit::Bit() {}

Bit::~Bit() {    
	if (_inputFile.is_open()) {
        _inputFile.close();
    }
    if (_datafile.is_open()) {
        _datafile.close();
    }
}

Bit::Bit(Bit& other) {
	*this = other;
}

Bit& Bit::operator=(Bit& other) {
    if (this != &other) {
        this->_MapData = other._MapData;
    }
    return *this;
}

void Bit::exchange(const std::string &fileName) {
	Filecheck(fileName);
	Parsing(_datafile);
	InputFileCheck(_inputFile);
}

void Bit::Filecheck(const std::string &fileName) {

    _inputFile.open(fileName.c_str());
    if (!_inputFile.is_open() || _inputFile.peek() == EOF) {
        throw std::runtime_error("Error: could not open input file.");
        return;
    }

    _datafile.open("data.csv");
    if (!_datafile.is_open() || _datafile.peek() == EOF) {
        throw std::runtime_error("Error: could not open target file.");
        return;
    }
}


void Bit::Parsing(std::ifstream &file) {
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::size_t commaPosition = line.find(',');

		std::string key = line.substr(0, commaPosition);
		std::string valueStr = line.substr(commaPosition + 1);

		float value = StringToFloat(valueStr);

		this->_MapData[key] = value;
	}
	file.close();
}

float Bit::StringToFloat(const std::string &val) {

	float tmp;
	std::stringstream(val) >> tmp;
	return tmp;
}

std::string Bit::trim(const std::string& str) {
	std::size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
		return str;
	}
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

void Bit::InputFileCheck(std::ifstream &InputFile) {

	std::string line;
	std::getline(InputFile, line);

	if (line != "date | value") {
		throw std::runtime_error("Error: invalid file format.");
		return;
	}

	while (std::getline(InputFile, line)) {

		if (line.empty()) {
			std::cout << "There is an empty line." << std::endl;
		}

		std::size_t pipe = line.find("|");
		if (pipe == std::string::npos) {
			std::cout << "Error: bad input -> " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipe));
		std::string value = trim(line.substr(pipe + 1));

		if (!DateCheck(date)) {
			continue;
		}

		if (!ValueCheck(value)) {
			continue;
		}

		float rate = StringToFloat(value);
		
		std::cout << std::fixed;
		std::cout << date << " => " << rate << " = " << rate * FindRate(date) << std::endl;

	}
}

bool Bit::ValueCheck(const std::string &value) {
	if (value.empty()) {
		std::cerr << "Error: empty value!" << std::endl;
		return false;
	}

	bool hasDecimalPoint = false;
	bool hasDigit = false;

	int sign = 0;
	if (value[0] == '-' || value[0] == '+') {
		sign++;
	}

	for (int i = sign; i < (int)value.length(); i++) {
		if (std::isdigit(value[i])) {
			hasDigit = true;
		} else if (value[i] == '.' && !hasDecimalPoint) {
			hasDecimalPoint = true;
		} else if (value[i] == 'f' && i == (int)value.length() - 1) {
			continue;
		} else {
			std::cerr << "Error: not a valid number: " << value << std::endl;
			return false;
		}
	}

	if (!hasDigit) {
		std::cerr << "Error: not a valid number: " << value << std::endl;
		return false;
	}

	float num = StringToFloat(value);
	if (num < 0) {
		std::cerr << "Error: negative value: " << value << std::endl;
		return false;
	}
	
	else if (num > 1000) {
		std::cerr << "Error: value out of range: " << value << std::endl;
		return false;
	}
	return true;
}

bool Bit::DateCheck(const std::string &date) {
	if (date.empty()) {
		std::cerr << "Error: empty value!" << std::endl;
		return false;
	}
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << "Error: not a valid date: " << date << std::endl;
		return false;
	}

	for (int i = 0; i < 10; i++) {
		if ((i != 4 && i != 7) && !std::isdigit(date[i])) {
			std::cerr << "Error: not a valid date: " << date << std::endl;
			return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2024) {
		std::cerr << "Error: year out of range: " << year << std::endl;
		return false;
	}
	if (month < 1 || month > 12) {
		std::cerr << "Error: month out of range: " << month << std::endl;
		return false;
	}
	if (day < 1 || day > 31) {
		std::cerr << "Error: day out of range: " << day << std::endl;
		return false;
	}

	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			std::cerr << "Error: day out of range for February: " << day << std::endl;
			return false;
		}
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		std::cerr << "Error: day out of range for month: " << day << std::endl;
		return false;
	}

	return true;
}

float Bit::FindRate(const std::string &date)
{
    std::map<std::string, float>::iterator it = _MapData.find(date);

    if (it != _MapData.end()) {
        return it->second;
    }

    it = _MapData.lower_bound(date);

    if (it == _MapData.begin())
        throw std::out_of_range("No data available for the given date");

    --it;
    return it->second;
}


