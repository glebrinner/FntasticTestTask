//
//  main.cpp
//  Symb
//
//  Created by Gleb Rinner on 14.12.2021.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string Input = "din";
    string OutPut = "";
    
    for(char Ch : Input){
        int Temp = 0;
        for(char Checker : Input){
            if(Ch == Checker){
                Temp += 1;
            }
        }
        if(Temp == 1){
            OutPut = OutPut + "(";
        } else {
            OutPut = OutPut + ")";
        }
    }
    
    cout<< OutPut;
    
    return 0;
}
