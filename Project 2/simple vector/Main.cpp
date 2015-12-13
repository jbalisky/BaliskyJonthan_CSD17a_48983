/* 
 File:   Game.cpp
 Author: Jonathan Balisky
 Created on July 25, 2015, 9:18 pM
 Purpose:  Mastermind .  
 */

//Libraries 

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

//User libraries

using namespace std;
//structured data

//Functions Prototypes


//Global 

int main(int argc, char** argv) {

    const int SIZE = 4;
    //Variables 

    srand(time(0));//setting the time seed
    
    
    //variables here
    bool swap = false; // foe bubble swap function
   int n=30;
   int i=0;
   int temp;
   vector<int>data(n);
   
    //swap here
    
    do {
        swap= false;
        for (i=0; i<n-1; i++){
            if ( data[i] > data[i+1]){
              //placeholder swap
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = data[i];
                
                swap = true;
            }
        }
    } while (swap==true);   
    
    return 0;
}

