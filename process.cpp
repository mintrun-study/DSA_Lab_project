#include "process.h"
#include "sort.h"
#include "time.h"

vector<int> input; vector<int> arr_copy;
int n;

string getAlgoName(const string& s) {
    if (s == "selection-sort")  return "Selection Sort";
    if (s == "insertion-sort")  return "Insertion Sort";
    if (s == "binary-insertion-sort") return "Binary Insertion Sort";
    if (s == "bubble-sort")     return "Bubble Sort";
    if (s == "shaker-sort")     return "Shaker Sort";
    if (s == "shell-sort")      return "Shell Sort";
    if (s == "heap-sort")       return "Heap Sort";
    if (s == "merge-sort")      return "Merge Sort";
    if (s == "quick-sort")      return "Quick Sort";
    if (s == "counting-sort")   return "Counting Sort";
    if (s == "radix-sort")      return "Radix Sort";
    if (s == "flash-sort")      return "Flash Sort";
    if (s == "selection-sort-optimize") return "Selection Sort Optimize";
    return s;
}

string getOrderName(const string& s) {
    if (s == "-rand")    return "Randomize";
    if (s == "-sorted")  return "Sorted";
    if (s == "-rev")     return "Reversed";
    if (s == "-nsorted") return "Nearly Sorted";
    return s;
}

typedef void (*SortFunction1)(vector<int>& arr, int n,  long long & count_comparision);
typedef void (*SortFunction2)(vector<int>& arr, int n);

SortFunction1 SortingAlgorithm(const string& algorithm){
    if (algorithm == "selection-sort") return selectionSort;
    if (algorithm == "insertion-sort") return insertionSort;
    if (algorithm == "shell-sort")     return shellSort;
    if (algorithm == "bubble-sort")    return bubbleSort;
    if (algorithm == "heap-sort")      return heapSort;
    if (algorithm == "merge-sort")     return mergeSort;
    if (algorithm == "quick-sort")     return quickSort;
    if (algorithm == "radix-sort")     return radixSort;
    if (algorithm == "counting-sort")  return countingSort;
    if (algorithm == "binary-insertion-sort") return binaryinsertionSort;
    if (algorithm == "shaker-sort")    return shakerSort;
    if (algorithm == "flash-sort")     return flashSort;
    if (algorithm == "selection-sort-optimize") return selectionSort_optimize1;
    return nullptr;
}

SortFunction2 SortingAlgorithm2(const string& algorithm){
    if (algorithm == "selection-sort") return selectionSort;
    if (algorithm == "insertion-sort") return insertionSort;
    if (algorithm == "shell-sort")     return shellSort;
    if (algorithm == "bubble-sort")    return bubbleSort;
    if (algorithm == "heap-sort")      return heapSort;
    if (algorithm == "merge-sort")     return mergeSort;
    if (algorithm == "quick-sort")     return quickSort;
    if (algorithm == "radix-sort")     return radixSort;
    if (algorithm == "counting-sort")  return countingSort;
    if (algorithm == "binary-insertion-sort") return binaryinsertionSort;
    if (algorithm == "shaker-sort")    return shakerSort;
    if (algorithm == "flash-sort")     return flashSort;
    if (algorithm == "selection-sort-optimize") return selectionSort_optimize1;
    return nullptr;
}

// Hàm đa năng: Nhận vào tên thuật toán, một mảng, và hàm sắp xếp tương ứng
pair<double,long long> measureTimeCompare(const string algorithm, vector<int>& arr, int n, string output) {
    pair<double,long long> ans;
    long long cnt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    
    if(output == "-time"){
        SortFunction2 sortFunc2 = SortingAlgorithm2(algorithm);
        sortFunc2(arr,n);
    }
    else{
        SortFunction1 sortFunc = SortingAlgorithm(algorithm);
        sortFunc(arr,n,cnt); // Thực thi thuật toán được truyền vào
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    ans.first = duration.count();
    ans.second = cnt;
    return ans;
}

void ReadFile(string input_file, vector<int> & a, int& n    ){
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
    
    auto output = measureTimeCompare(algorithm,arr_copy,n, output_param);

    if(output_param == "-both" || output_param == "-time") cout<<"Running time: "<<output.first<< " ms" <<endl;
    if(output_param == "-both" || output_param == "-comp")cout<<"Comparisons: "<<output.second<<endl;

    WriteFile("output.txt", arr_copy, n);
}

// Command 2: Run on the data generated automatically with specified size and order
void runCommand2(const std::string& algorithm, int input_size, const std::string& input_order, const std::string& output_param){
    cout<<"ALGORITHM MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm) <<endl;
    cout<<"Input size: "<< input_size <<endl;
    cout<<"Input order: "<< getOrderName(input_order) <<endl;
    cout << "-------------------------\n";

    GenerateData(input, input_size, input_order);
    arr_copy = input;

    WriteFile("input.txt",arr_copy , input_size);

    auto output = measureTimeCompare(algorithm,arr_copy,input_size,output_param);
    if(output_param == "-both" || output_param == "-time") cout<<"Running time: "<<output.first<< " ms" <<endl;
    if(output_param == "-both" || output_param == "-comp")cout<<"Comparisons: "<<output.second<<endl;

    WriteFile("output.txt", arr_copy, input_size);
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

        auto output = measureTimeCompare(algorithm, arr, input_size,output_param);
        if (output_param == "-both" || output_param == "-time")
            cout << "Running time: " << output.first << " ms" << "\n";
        if (output_param == "-both" || output_param == "-comp")
            cout << "Comparisons: " << output.second << "\n";
    }
}

// Command 4: Run two sorting algorithms on user-provided data
void runCommand4(const std::string& algorithm_1, const std::string& algorithm_2, const std::string& input_file){
    cout<<"COMPARE MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm_1) << " | " << getAlgoName(algorithm_2) <<endl;
    cout<<"Input file: "<< input_file <<endl;
    //Main Command
    ReadFile(input_file,input,n);
    cout<<"Input size: "<<n<<endl;
    cout << "-------------------------\n";
    arr_copy = input;
    vector<int> arr_copy2 = input;
    auto output1 = measureTimeCompare(algorithm_1,arr_copy,n,"-both");
    
    auto output2 = measureTimeCompare(algorithm_2,arr_copy2,n,"-both");
    cout<<"Running time: " << output1.first << " ms | "<< output2.first << " ms" <<endl;
    
    cout<<"Comparisons: "<<output1.second << " | "<<output2.second <<endl;
}

// Command 5: Run two sorting algorithms on the data generated automatically with a specified size and order
void runCommand5(const std::string& algorithm_1, const std::string& algorithm_2, int input_size, const std::string& input_order){
    cout<<"COMPARE MODE \n";
    cout<<"Algorithm: " << getAlgoName(algorithm_1) << " | " << getAlgoName(algorithm_2) <<endl;
    cout<<"Input size: "<< input_size <<endl;
    cout<<"Input order: "<< getOrderName(input_order) <<endl;
    cout << "-------------------------\n"; 
    
    GenerateData(input,input_size,input_order);
    WriteFile("input.txt",input,input_size);

    arr_copy = input;
    vector<int> arr_copy2 = input;
    auto output1 = measureTimeCompare(algorithm_1,arr_copy,input_size,"");

    auto output2 = measureTimeCompare(algorithm_2,arr_copy2,input_size,"");
    cout<<"Running time: " << output1.first << " ms" << " | "<<output2.first<< " ms"<<endl;

    cout<<"Comparisons: "<<output1.second << " | "<<output2.second <<endl;
}

// Command All: Run all sorting algorithms on generated data and print comparison table
void runCommand6(int input_size, const string& input_order, const string& output_param){
    cout << "ALGORITHM MODE \n";
    cout << "Input size: " << input_size << "\n";
    cout << "Input order: " << getOrderName(input_order) << "\n\n";

    string algos[] = {
        "selection-sort-optimize", "insertion-sort", "binary-insertion-sort",
        "bubble-sort", "shaker-sort", "shell-sort", "heap-sort",
        "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"
    };

    vector<int> base;
    GenerateData(base, input_size, input_order);

    double times[12];
    long long cmps[12];

    // Run all algorithms and print results
    for(int i = 0; i < 12; i++){
        vector<int> arr = base;
        auto result = measureTimeCompare(algos[i], arr, input_size, output_param);
        times[i] = result.first;
        cmps[i]  = result.second;

        cout << getAlgoName(algos[i]) << ":\n";
        cout << "-------------------------\n";
        if(output_param == "-both" || output_param == "-time")
            cout << "Running time: " << times[i] << " ms\n";
        if(output_param == "-both" || output_param == "-comp")
            cout << "Comparisons: " << cmps[i] << "\n";
        cout << "\n";
    }

    // Sort index array to get ranking
    int rank[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

    cout << "RANKING\n";
    cout << "-------------------------\n";

    if(output_param == "-both" || output_param == "-time"){
        for(int i = 0; i < 12; i++)
            for(int j = i+1; j < 12; j++)
                if(times[rank[i]] > times[rank[j]]) swap(rank[i], rank[j]);

        cout << "By Running Time:\n";
        for(int i = 0; i < 12; i++)
            cout << i+1 << ". " << getAlgoName(algos[rank[i]]) << ": " << times[rank[i]] << " ms\n";
        cout << "\n";
    }

    if(output_param == "-both" || output_param == "-comp"){
        for(int i = 0; i < 12; i++) rank[i] = i; // reset
        for(int i = 0; i < 12; i++)
            for(int j = i+1; j < 12; j++)
                if(cmps[rank[i]] > cmps[rank[j]]) swap(rank[i], rank[j]);

        cout << "By Comparisons:\n";
        for(int i = 0; i < 12; i++)
            cout << i+1 << ". " << getAlgoName(algos[rank[i]]) << ": " << cmps[rank[i]] << "\n";
    }
}