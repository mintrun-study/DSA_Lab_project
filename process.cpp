#include "process.h"
#include "sort.h"

vector<int> input; vector<int> arr_copy;
int n;

string getAlgoName(const string& s) {
    if (s == "selection-sort")  return "Selection Sort";
    if (s == "insertion-sort")  return "Insertion Sort";
    if (s == "bubble-sort")     return "Bubble Sort";
    if (s == "shaker-sort")     return "Shaker Sort";
    if (s == "shell-sort")      return "Shell Sort";
    if (s == "heap-sort")       return "Heap Sort";
    if (s == "merge-sort")      return "Merge Sort";
    if (s == "quick-sort")      return "Quick Sort";
    if (s == "counting-sort")   return "Counting Sort";
    if (s == "radix-sort")      return "Radix Sort";
    if (s == "flash-sort")      return "Flash Sort";
    return s;
}

string getOrderName(const string& s) {
    if (s == "-rand")    return "Randomize";
    if (s == "-sorted")  return "Sorted";
    if (s == "-rev")     return "Reversed";
    if (s == "-nsorted") return "Nearly Sorted";
    return s;
}

typedef void (*SortFunction)(vector<int>& arr, int n,  long long & count_comparision);

SortFunction SortingAlgorithm(const string& algorithm){
    if (algorithm == "selection-sort") return selectionSort;
    if (algorithm == "insertion-sort") return insertionSort;
    if (algorithm == "shell-sort")     return shellSort;
    //if (algorithm == "bubble-sort")    return bubbleSort;
    if (algorithm == "heap-sort")      return heapSort;
    if (algorithm == "merge-sort")     return mergeSort;
    //if (algorithm == "quick-sort")     return quickSort;
    if (algorithm == "radix-sort")     return radixSort;
    //if (algorithm == "counting-sort")  return countingSort;
    if (algorithm == "binary-insertion-sort") return binaryinsertionSort;
    //if (algorithm == "shaker-sort")    return shakerSort;
    if (algorithm == "flash-sort")     return flashSort;
    return nullptr;
}

// Hàm đa năng: Nhận vào tên thuật toán, một mảng, và hàm sắp xếp tương ứng
pair<double,long long> measureTimeCompare(SortFunction sortFunc, vector<int>& arr, int n) {
    pair<double,long long> ans;
    long long cnt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    

    sortFunc(arr,n,cnt); // Thực thi thuật toán được truyền vào
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    ans.first = duration.count();
    ans.second = cnt;
    return ans;
}

void ReadFile(string input_file, vector<int> & a, int& n){
    ifstream f(input_file);
    if(!f){
        cout<<"Can not open file" <<endl;
        return;
    }
    else{
        int x;
        f >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            f >> a[i];
        }
    }
    n = a.size();
    f.close();
}

void WriteFile(const string& filename, const vector<int>& a, int n) {
    ofstream f(filename);
    f << n << "\n";
    for (int i = 0; i < n; i++) f << a[i] << " ";
    f << "\n";
    f.close();
}

void GenerateData(vector<int>& a, int n, const string& order) {
    a.resize(n);
    if (order == "-rand") {
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++) a[i] = rand() % n;
    }
    else if (order == "-sorted") {
        for (int i = 0; i < n; i++) a[i] = i;
    }
    else if (order == "-rev") {
        for (int i = 0; i < n; i++) a[i] = n - i;
    }
    else if (order == "-nsorted") {
        for (int i = 0; i < n; i++) a[i] = i;
        srand((unsigned)time(NULL));
        for (int i = 0; i < max(1, n/100); i++)
            swap(a[rand()%n], a[rand()%n]);
    }
}

// Command 1: Run a sorting algorithm on user-provided data
void runCommand1(const std::string& algorithm, const std::string& input_file, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm) <<endl;
    cout<<"Input file: " << input_file <<endl;
    ReadFile(input_file, input,n);
    arr_copy = input;
    cout<<"Input size: "<<n<<endl;
    cout << "-------------------------\n";
    
    auto output = measureTimeCompare(SortingAlgorithm(algorithm),arr_copy,n);

    if(output_param == "-both" || output_param == "-time") cout<<"Running time: "<<output.first<<endl;
    if(output_param == "-both" || output_param == "-comp")cout<<"Comparisions: "<<output.second<<endl;

    WriteFile("output.txt", arr_copy, n);
}

// Command 2: Run on the data generated automatically with specified size and order
void runCommand2(const std::string& algorithm, int input_size, const std::string& input_order, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm) <<endl;
    cout<<"Input size: "<< input_size <<endl;
    cout<<"Input order: "<< getOrderName(input_order) <<endl;
    cout << "-------------------------\n";

    vector<int> arr;
    GenerateData(arr, input_size, input_order);

    WriteFile("input.txt", arr, input_size);

    auto output = measureTimeCompare(SortingAlgorithm(algorithm),arr,input_size);
    if(output_param == "-both" || output_param == "-time") cout<<"Running time: "<<output.first<<endl;
    if(output_param == "-both" || output_param == "-comp")cout<<"Comparisions: "<<output.second<<endl;

    WriteFile("output.txt", arr, input_size);
}

// Command 3: Run a sorting algorithm on ALL data arrangements of a specified size
void runCommand3(const std::string& algorithm, int input_size, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm) <<endl;
    cout<<"Input size: "<<input_size<<endl<<endl;
    
    string orders[] = {"-rand", "-nsorted", "-sorted", "-rev"};
    string fileNames[] = {"input_1.txt", "input_2.txt",  "input_3.txt", "input_4.txt"};
    
    for (int i = 0; i < 4; i++) {
        vector<int> arr;
        GenerateData(arr, input_size, orders[i]);
        WriteFile(fileNames[i], arr, input_size);

        cout << "\nInput order: " << getOrderName(orders[i]) << "\n";
        cout << "-------------------------\n";

        SortFunction sf = SortingAlgorithm(algorithm);
        if (sf == nullptr) { cout << "Unknown algorithm\n"; return; }

        auto output = measureTimeCompare(sf, arr, input_size);
        if (output_param == "-both" || output_param == "-time")
            cout << "Running time: " << output.first << " milliseconds\n";
        if (output_param == "-both" || output_param == "-comp")
            cout << "Comparisons: " << output.second << "\n";
    }
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
