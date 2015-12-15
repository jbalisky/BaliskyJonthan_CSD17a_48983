/* 
 * File:   main.cpp
 * Author: Jonathan
 *
 * Created on December 14, 2015, 8:06 PM
 */

#include "Prob1Random.h"
#include <iostream>
using namespace std;
Prob1Random::Prob1Random(const char a, const char *b){
    //setting time seed
    srand(time(0));
    //allocating memory
    set = new char [static_cast<int>(a)];
    nset = a;
    freq = new int [static_cast<int>(a)];
    //fill set with char array
    //setting freq to 0
    
    for(int i = 0;i<static_cast<int>(a);i++){
        set[i] = b[i];
        freq[i]=0;
    }
    for(int i = 0; i<static_cast<int>(a);i++){
        cout<<set[i];
    }
    cout<<"\n\n";
    //setting number of randoms to zero
    numRand = 0;
}
Prob1Random::~Prob1Random(){
    //Deleting dynamic array
    delete []set;
    delete []freq;
    
}

