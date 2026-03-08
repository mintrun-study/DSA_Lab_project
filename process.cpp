#include "process.h"
#include "sort.h"

typedef void (*SortFunction)(std::vector<int>&);

SortFunction SortingAlgorithm(const string& algorithm){
    if (algorithm == "selection-sort") return selectionSort;
    if (algorithm == "insertion-sort") return insertionSort;
    //if (algorithm == "shell-sort")     return shellSort;
    //if (algorithm == "bubble-sort")    return bubbleSort;
    //if (algorithm == "heap-sort")      return heapSort;
    if (algorithm == "merge-sort")     return mergeSort;
    //if (algorithm == "quick-sort")     return quickSort;
    //if (algorithm == "radix-sort")     return radixSort;
    //if (algorithm == "counting-sort")  return countingSort;
    //if (algorithm == "binary-insertion-sort") return binaryInsertionSort;
    //if (algorithm == "shaker-sort")    return shakerSort;
    if (algorithm == "flash-sort")     return flashSort;
    return nullptr;
}

// Hàm đa năng: Nhận vào tên thuật toán, một mảng, và hàm sắp xếp tương ứng
double measureRunningTime(SortFunction sortFunc, std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    
    sortFunc(arr); // Thực thi thuật toán được truyền vào
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    
    return duration.count();
}

void ReadFile(string input_file){
    //Do
}



// Command 1: Run a sorting algorithm on user-provided data
void runCommand1(const std::string& algorithm, const std::string& input_file, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " <<algorithm<<endl;
    cout<<"Input file: " << input_file<<endl;
    cout << "-------------------------\n";
}

// Command 2: Run on the data generated automatically with specified size and order
void runCommand2(const std::string& algorithm, int input_size, const std::string& input_order, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " <<algorithm<<endl;
    cout<<"Input size: "<<input_size<<endl;
    cout<<"Input order: "<<input_order<<endl;
    cout << "-------------------------\n";
}

// Command 3: Run a sorting algorithm on ALL data arrangements of a specified size
void runCommand3(const std::string& algorithm, int input_size, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " <<algorithm<<endl;
    cout<<"Input size: "<<input_size<<endl<<endl;
    //Main Command
    cout << "-------------------------\n";
    

}

// Command 4: Run two sorting algorithms on user-provided data
void runCommand4(const std::string& algorithm_1, const std::string& algorithm_2, const std::string& input_file){
    cout<<"COMPARE MODE \n";
    cout<<"Algorithm: " <<algorithm_1<<"||"<<algorithm_2<<endl;
    cout<<"Input file: "<< input_file<<endl;
    //Main Command
}

// Command 5: Run two sorting algorithms on the data generated automatically with a specified size and order
void runCommand5(const std::string& algorithm_1, const std::string& algorithm_2, int input_size, const std::string& input_order){
    cout<<"COMPARE MODE \n";
    cout<<"Algorithm: " <<algorithm_1<<"||"<<algorithm_2<<endl;
    cout<<"Input size: "<<input_size<<endl;
    cout<<"Input order: "<<input_order<<endl;
    cout << "-------------------------\n"; 
}
