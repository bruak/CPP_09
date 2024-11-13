#pragma once

#include <vector>
#include <deque>
#include <stdexcept>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>


#define ERR_NOT_PZTV "Error: not a positive number."
#define ERR_TOO_LARGE "Error: too large a number."
#define ERR_NOT_NUM "Error: not a number."
#define MAX_INT_STR "2147483647"
#define BEFORE "Before: "
#define ERR_NO_ARG "Error: no arguments provided."

class MergeInsertSort {
	public:
		MergeInsertSort(char **argv);
		~MergeInsertSort();
		MergeInsertSort(const MergeInsertSort& other);
		bool is_negative(const std::string &str);
		bool is_too_large(const std::string &str);
		void check_input(char **argv);
		void values_to_vector(char **argv);
		void values_to_deque(char **argv);
		void Print_Values(std::vector<int> &container);
		void GetTimeAndSort(std::vector<int> &vec);
		void GetTimeAndSort(std::deque<int> &deq);
		void PrintTimeProcess();
		void mergeInsertSort(std::vector<int> &vec);
		void mergeInsertSort(std::deque<int> &deq);
		void insertionSort(std::vector<int> &vec);
		void insertionSort(std::deque<int> &deq);
		MergeInsertSort &operator=(const MergeInsertSort &other);

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		clock_t _start;
		clock_t _end;
		double _VecTime;
		double _DeqTime;

};
