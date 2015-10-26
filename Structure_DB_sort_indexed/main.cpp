/* 
 * File:   main.cpp
 * Author: rcc
 *Purpose show utilty of a struture refernced to a databse short indexed clumn in a databse
 * Created on October 6, 2015, 11:18 AM
 * home work: convert to dot operator for sturcture notation + array notation
 */
//system lib
#include<iostream>
#include <cstdlib>
#include <ctime>
//Namespace
using namespace std;
//user libray

#include "IndexedColumn.h"

//Functions protos
IndxCol *fill(int);
void prntStr(IndxCol *,int, int);
void prntAry(int *,int, int);
void mrkSort(IndxCol *);

/*
 * 
 */
int main(int argc, char** argv) {
    //rand
    srand(static_cast<unsigned int>(time(0)));
    //allocate memory for sturct
     int n =100, col =10; //number of elements
     int perLine = 10;
    IndxCol *str=fill(n); //call
    
    
    
    cout<<"The original index array"<<endl;
    prntAry(str->indx,str->size, col);
    cout<<"The original data array"<<endl;
    prntAry(str->array,str->size, col);
    cout<<"The original data array using the index array"<<endl;
    prntStr(str,str->size, col);
    
    mrkSort(str);//Sorting
    
        
    cout<<"The original index array after sort"<<endl;
    prntAry(str->indx,str->size, col);
    cout<<"The original data array after sort"<<endl;
    prntAry(str->array,str->size, col);
    cout<<"The original data array using the index array after sort"<<endl;
    prntStr(str,str->size, col);
    
    
    
    return 0;
}

IndxCol *fill(int n){
    IndxCol *col = new IndxCol;
    
    if (n <=1)n=2; //Checking size of N
    
    col->size=n;
    col->array= new int[n];
    col->indx = new int[n];
    
    //fill array
    for(int i=0; i<n; i++){
        col->indx[i]=i;
        col->array[i]= rand()%90+10;
        
    }
    return col;
}

void prntStr (IndxCol *a,int size, int perLine){
    cout<<endl;
    for (int i =0; i<a->size; i++){
        cout<<a->array[a->indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}
void prntAry (int *a,int size, int perLine){
    cout<<endl;
    for (int i =0; i<size; i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}

void mrkSort(IndxCol *a){
    //pick a postion to sort
    for(int pos=0; pos<(*a).size-1;pos++){
        //sort a list by the postion
        for(int lst = pos+1;lst<a->size; lst++){
            if(a->array[a->indx[pos]]>a->array[a->indx[lst]]){
                int temp =a->indx[pos];
                a->indx[pos]= a->indx[lst];
                a->indx[lst]=temp;
            }
        }
    }
}