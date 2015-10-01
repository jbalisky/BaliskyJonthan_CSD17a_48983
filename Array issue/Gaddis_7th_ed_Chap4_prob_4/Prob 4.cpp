/* 
 File:   Prob 10.cpp
 Author: Jonathan Balisky
 Created on Sept 10, 2015, :33 PM
 Purpose: Which Rectangle is bigger! 
 */

//Library iostream
//No Prototypes

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global const none
int * prepare(int);
void sort(int *);


int main(int argc, char** argv) {

    //Variables 

    
    int *table;//Table for numbers
    int size; //Size of array
    
    srand(time(0)); //Setting the time seed
    
    cout<<"Input size of array ";
    cin>>size; //Input the size of the array
    
    table=prepare(size); //Filling table putting it into table
    
    
 
    
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
        

        cout<<"Array = "<<table[i]; //For diagonostics 
    }
   return table;
}    
    


/***************************************Sort***************************************************
 * Purpose: To Sort all the user guesses to show I can do it...so HA! Using a bubble sort
 * Input: table, counter, level
 * Output:none
 
 ***********************************************************************************************/
void sort(char **table, int counter, int level){
    
    bool swap = false;//For the bubble swap function
    int  indx = 0; //Second index location for table       
   
    cout<<"Unsorted answers from you!!"<<endl;
    for(int i = 0;i<counter; i++){
        for(int j = 0;j<level; j++){
            cout<<table[i][j];
        }
        cout<<endl;
    }
    
    do{
        swap = false;
        
        for(int i = 0; i<counter-1; i++){ //counter -1 because bubble swap is always columns - 1
            indx = 0;
            while(table[i][indx]==table[i+1][indx] && indx<level)indx++;//Checking to see if current
                                                                         //index is equal then going to next location if they 
                                                                         //are equal. 
            if ( table[i][indx]>table[i+1][indx]){ //If that row and col. not equal 
                                                  //then check if first is larger if it is then swap all numbers
                //cout<<"i>i+1"<<endl;//For diagnostics 
                for(int j = 0; j <level; j++){ //Swapping each 2 rows and their respective columns until all the rows are swapped
                table [i][j] = table [i][j]^table[i+1][j]; //in place swap. to hopefully make Dr lehr happy so he give me extra credit
                table [i+1][j] = table [i][j]^table[i+1][j];
                table [i][j] = table [i][j]^table[i+1][j];
                }
                swap = true;            
            }
                
        }
    }while(swap == true);
    
    cout<<"Sorted answers via bubble sorts !!"<<endl;
    for(int i = 0;i<counter; i++){
        for(int j = 0;j<level; j++){
            cout<<table[i][j];
        }
        cout<<endl;
    }
    
    
    
    
}