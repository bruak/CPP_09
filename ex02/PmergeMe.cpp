#include "PmergeMe.hpp"

MergeInsertSort::MergeInsertSort(char **argv) {
	check_input(argv);
	values_to_vector(argv);
	values_to_deque(argv);
	Print_Values(_vector);
	GetTimeAndSort(_vector);
	GetTimeAndSort(_deque);
	Print_Values(_vector);
	PrintTimeProcess();
}

MergeInsertSort::~MergeInsertSort() {}

MergeInsertSort& MergeInsertSort::operator=(const MergeInsertSort& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

MergeInsertSort::MergeInsertSort(const MergeInsertSort& other) {
	this->_vector = other._vector;
	this->_deque = other._deque;
}

bool MergeInsertSort::is_negative(const std::string& str) {
	return str.empty() || str[0] == '-';
}

bool MergeInsertSort::is_too_large(const std::string& str) {
	return str.length() > 10 || (str.length() == 10 && str > MAX_INT_STR);
}

void MergeInsertSort::check_input(char **argv) {
	for (int i = 1; argv[i] != NULL; i++) {
		std::string str = argv[i];
		if (str.empty() || str[0] == '-')
			throw std::invalid_argument(ERR_NOT_PZTV);
		if (str.length() > 10 || (str.length() == 10 && str > MAX_INT_STR))
			throw std::invalid_argument(ERR_TOO_LARGE);
		for (size_t j = 0; j < str.length(); j++) {
			if (!isdigit(str[j]))
				throw std::invalid_argument(ERR_NOT_NUM);
		}
	}
}

void MergeInsertSort::values_to_vector(char **argv) {
	for (int i = 1; argv[i] != NULL; i++) {
		_vector.push_back(atoi(argv[i]));
	}
}

void MergeInsertSort::values_to_deque(char **argv) {
	for (int i = 1; argv[i] != NULL; i++) {
		_deque.push_back(atoi(argv[i]));
	}
}

void MergeInsertSort::Print_Values(std::vector<int>& container) {
	std::cout << BEFORE;
	for (size_t i = 0; i < container.size() && i < 10; i++) {
		std::cout << container[i] << " ";
	}
	if (container.size() > 10)
		std::cout << " [...]";
	std::cout << std::endl;

}


void MergeInsertSort::GetTimeAndSort(std::vector<int>& vec) {
	_start = clock();
	mergeInsertSort(vec);
	_end = clock();
	_VecTime = static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1000;
}

void MergeInsertSort::GetTimeAndSort(std::deque<int>& deq) {
	_start = clock();
	mergeInsertSort(deq);
	_end = clock();
	_DeqTime = static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1000;
}


void MergeInsertSort::PrintTimeProcess() {
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << _VecTime << " ms\n";
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << _DeqTime << " ms\n";
}

void MergeInsertSort::mergeInsertSort(std::vector<int>& vec) {
	if (vec.size() <= 10) {
		insertionSort(vec);
		return;
	}
	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

void MergeInsertSort::mergeInsertSort(std::deque<int>& deq) {
	if (deq.size() <= 10) {
		insertionSort(deq);
		return;
	}
	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

void MergeInsertSort::insertionSort(std::vector<int>& vec) {
	for (size_t i = 1; i < vec.size(); i++) {
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void MergeInsertSort::insertionSort(std::deque<int>& deq) {
	for (size_t i = 1; i < deq.size(); i++) {
		int key = deq[i];
		int j = i - 1;
		while (j >= 0 && deq[j] > key) {
			deq[j + 1] = deq[j];
			j--;
		}
		deq[j + 1] = key;
	}
}
