#ifndef PROCESS
#define PROCESS

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;

extern std::vector<int> input; extern std::vector<int> arr_copy;
extern int n;


// Command 1: Run a sorting algorithm on user-provided data
void runCommand1(const std::string& algorithm, const std::string& input_file, const std::string& output_param);

// Command 2: Run on the data generated automatically with specified size and order
void runCommand2(const std::string& algorithm, int input_size, const std::string& input_order, const std::string& output_param);

// Command 3: Run a sorting algorithm on ALL data arrangements of a specified size
void runCommand3(const std::string& algorithm, int input_size, const std::string& output_param);

// Command 4: Run two sorting algorithms on user-provided data
void runCommand4(const std::string& algorithm_1, const std::string& algorithm_2, const std::string& input_file);

// Command 5: Run two sorting algorithms on the data generated automatically with a specified size and order
void runCommand5(const std::string& algorithm_1, const std::string& algorithm_2, int input_size, const std::string& input_order);

#endif