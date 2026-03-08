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
    if(argc < 5) cout<<"invaild number of arguments"<<endl;
    return 1;
    
    string mode = argv[1];

    if(mode == "-a"){
        string algorithm = argv[2];

        if(argc == 5){
            
            if(isNumber(argv[3])){
                //Command 3
            }
            else{
                //Command 1
            }
        }
        else if(argc == 6){
            //Command 2
        }
    }
    else if(mode == "-c"){
        string algorithm1, algorithm2;
        if(argc == 5){
            //Command 4
        }
        else if(argc == 6){
            //Command 5
        }
    }
    else{
        cout<<"Unknown mode"<<endl;

        return 1;
    }
    return 0;
}