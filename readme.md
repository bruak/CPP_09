# CPP Module 09

This repository contains the exercises for CPP Module 09, focusing on C++ Standard Template Library (STL) containers and algorithms with practical applications.

## Overview

This module builds upon the STL knowledge from previous modules and applies it to real-world scenarios. The exercises involve working with financial data, implementing calculator logic, and sorting algorithms using various STL containers such as maps, stacks, vectors, and deques. This module demonstrates how to leverage the power and efficiency of STL containers and algorithms in solving complex problems.

## Exercises

### Exercise 00: Bitcoin Exchange

A program that calculates the value of Bitcoin holdings based on a database and an input file.

#### Features:
- Parsing date-value pairs from CSV and custom input files
- Storing and retrieving exchange rates using std::map
- Finding the closest date when an exact date match isn't available
- Robust error handling for various input conditions

#### Implementation Details:
- Implementation of `BitcoinExchange` class that manages exchange rate data
- Input validation for dates (format: YYYY-MM-DD) and values
- Error handling for invalid inputs, empty values, negative values, etc.
- Usage of std::map to efficiently store and retrieve date-indexed data
- Date interpolation using lower_bound functionality

### Exercise 01: Reverse Polish Notation

A calculator that evaluates expressions in Reverse Polish Notation (RPN) format.

#### Features:
- Stack-based implementation of RPN calculator
- Support for basic arithmetic operations (+, -, *, /)
- Error handling for invalid expressions
- Simple and efficient parsing of expressions

#### Implementation Details:
- Implementation of `RPN` class using std::stack
- Validation of input tokens (numbers and operators)
- Error handling for division by zero, insufficient operands, and invalid expressions
- Step-by-step evaluation of RPN expressions using stack operations

### Exercise 02: PmergeMe

An implementation of a hybrid sorting algorithm (Ford-Johnson merge-insert sort) using different STL containers.

#### Features:
- Implementation of the merge-insert sort algorithm with std::vector and std::deque
- Performance comparison between different container implementations
- Performance timing and reporting
- Input validation and error handling

#### Implementation Details:
- Implementation of `MergeInsertSort` class with methods for both container types
- Efficient sorting using divide-and-conquer and insertion sorting for smaller subsets
- Performance timing using clock_t for accurate measurements
- Proper error handling for invalid inputs (non-positive numbers, too large numbers, non-numeric inputs)
- Comparison of vector and deque sorting efficiency

## STL Components Used

### Containers
- std::map - Used in BitcoinExchange for date-indexed storage of exchange rates
- std::stack - Used in RPN calculator for operand and operator management
- std::vector - Used in PmergeMe for sorting implementation and performance comparison
- std::deque - Used in PmergeMe for sorting implementation and performance comparison

### Algorithms
- Merge sort - Used as part of the merge-insert sorting algorithm
- Insertion sort - Used for small sequences in the merge-insert sorting algorithm
- std::merge - Used to combine sorted subsequences in the merge-insert algorithm

### Iterators
- Map iterators - Used to navigate through and find values in the exchange rate map
- Vector/deque iterators - Used in the merge-insert sorting implementation

## Compilation

Each exercise comes with a Makefile that supports the following commands:
- `make`: Compile the program
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the entire program

## Requirements

- C++ compiler with C++98 standard support
- Linux/macOS environment
- All code must compile with the following flags:
```
c++ -Wall -Wextra -Werror -std=c++98
```

## Notes

These exercises demonstrate important C++ concepts such as:
- Practical application of STL containers for real-world problems
- Performance considerations when selecting container types
- Error handling and input validation techniques
- Working with date and numeric data
- Implementation of common algorithms using STL facilities

The module provides hands-on experience with using STL in financial applications, calculators, and algorithmic performance analysis, which are common scenarios in production software.