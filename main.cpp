#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "sort.h"
#include "process.h"

bool isNumber(string s){
    if(s.empty()) return false;
    for(char &c : s){
        if(!isdigit(c)) return false;
    }

    return true;
}

int main(int argc, char * argv[]){
    if(argc < 5){
    cout<<"invalid number of arguments"<<endl;
    return 1;
    }
    
    string mode = argv[1];

    if(mode == "-a"){
        const string algorithm = argv[2];

        if(argc == 5){
            
            if(isNumber(argv[3])){
                //Command 3
                int input_size = stoi(argv[3]);
                const string output = argv[4];
                runCommand3(algorithm,input_size,output);
            }
            else{
                //Command 1
                const string input_file = argv[3];
                string output = argv[4];
                runCommand1(algorithm,input_file,output);
            }
        }
        else if(argc == 6){
            //Command 2
            int input_size = stoi(argv[3]);
            const string input_order = argv[4];
            const string output = argv[5];
            runCommand2(algorithm,input_size,input_order,output);
        }
    }
    else if(mode == "-c"){
        const string algorithm1 = argv[2], algorithm2 = argv[3];
        if(argc == 5){
            //Command 4
            const string input_file = argv[4];
            runCommand4(algorithm1,algorithm2,input_file);
        }
        else if(argc == 6){
            //Command 5
            int input_size = stoi(argv[4]);
            const string input_order = argv[5];
            runCommand5(algorithm1,algorithm2,input_size,input_order);
        }
    }
    else if(mode == "-all"){
        if(argc == 5){
            int input_size = stoi(argv[2]);
            string input_order = argv[3];
            string output_param = argv[4];
            runCommand6(input_size, input_order, output_param);
        }
    }
    else{
        cout<<"Unknown mode"<<endl;
        return 1;
    }
    return 0;
}