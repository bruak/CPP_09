#pragma once 
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Bit {
	public:
		Bit();
		~Bit();
		Bit& operator=(Bit& other);
		Bit(Bit& other);

		std::string trim(const std::string &);
		void exchange(const std::string &);
		void Filecheck(const std::string &);
		void Parsing(std::ifstream &);
		void InputFileCheck(std::ifstream &);

		float FindRate(const std::string &);
		float StringToFloat(const std::string &);

		bool ValueCheck(const std::string &);
		bool DateCheck(const std::string &);
	private:
		std::map<std::string, float> _MapData;
		std::ifstream _datafile;
		std::ifstream _inputFile;
};