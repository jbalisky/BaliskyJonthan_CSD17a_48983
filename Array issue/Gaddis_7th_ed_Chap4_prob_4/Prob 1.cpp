/* 
 File:   Prob 10.cpp
 Author: Jonathan Balisky
 Created on Sept 10, 2015, :33 PM
 Purpose: Mean mode! 
 */

//Library iostream
//No Prototypes

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global const none
int * prepare(int);
void sort(int *, int);
float mean(int *, int);


int main(int argc, char** argv) {

    //Variables 

    
    int *table;//Table for numbers
    int size; //Size of array
    
    srand(time(0)); //Setting the time seed
    
    cout<<"Input size of array ";
    cin>>size; //Input the size of the array
    
    table=prepare(size); //Filling table putting it into table
    
    sort(table, size); //Sorting the array
    
    cout<<"The mean is = "<<mean(table, size)<<endl;
    
//    for(int i =0; i<size; i++){
//        cout<<table[i]<<" /n";
//        if (i%10 == 0) cout<<endl;
//    }
// 
    
    delete [] table;
    return 0;
}
/***************************************Prepare**************************************************
 * Purpose: Initializing values for the game.  
 * Input: answer, xs, os, guess, match, level
 * Output:
 * table
 
 ***********************************************************************************************/
int * prepare (int size){
    
    int *table;
    
    
//   int size = 10;
   
   table = new int [size]; //Creating a new array
  
    for (int i = 0; i<size; i++){
        table[i] = rand()%6; //Filling array with number from 0-5
        

       // cout<<"Array = "<<table[i]; //For diagonostics 
    }
   return table;
}    
    


/***************************************Sort***************************************************
 * Purpose: To Sort the array of numbers Using a bubble sort
 * Input: table, size
 * Output:none
 
 ***********************************************************************************************/
void sort(int *table, int size ){
    
    bool swap = false;//For the bubble swap function
          
   
    cout<<"Unsorted answers from you!!"<<endl;
    for(int i = 0;i<size; i++){
        if (i%10 == 0 && i > 1) cout<<endl;
        cout<<table[i];
       
    }
    
    do{
        swap = false;
       // cout<<endl<<"swap started"<<endl; //For Diag
        for(int i = 0; i<size-1; i++){ //counter -1 because arrays start at 01 and you cant swap the last one
           // cout<<endl<<"i = "<<i<<endl;
            if ( table[i]>table[i+1]){ //If col. not equal                               
                //cout<<"Table[i] = "<<table[i]<<"table[i+1] = "<<table[i+1]<<endl;//For diagnostics
                table [i] = table [i]^table[i+1]; //in place swap with the next number
                table [i+1] = table [i]^table[i+1];
                table [i] = table [i]^table[i+1];
                swap = true;
                }
                           
            }
    }while(swap == true);
    
            //cout<<endl<<"swap Ended"<<endl; //For Diag
    
    cout<<"Sorted answers via bubble sorts !!"<<endl;
    for(int i = 0;i<size; i++){
        if (i%10 == 0 && i != 0) cout<<endl;//Making the rows ten wide
        cout<<table[i];
        }
    cout<<endl;
       
 
}
/***************************************Mean**************************************************
 * Purpose: Mean of array  
 * Input: *table, size
 * Output: mean
 * 
 
 ***********************************************************************************************/
float  mean (int *table, int size){
    
    float avg = 0.0f, sum = 0.0f;
    
  
    for (int i = 0; i<size; i++){
        sum += table[i]; //Adding all the numbers together
         // cout<<"Array = "<<table[i]; //For diagonostics 
    }
    avg = sum/static_cast<float>(size);
   
   return avg;
}    
  