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

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};


using namespace std;

//Global const none
int * prepare(int);
void sort(int *, int);
float mean(int *, int);
statsResult *avgMedMode(int *,int);

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
    
  
    for (int i = 0; i<size-1; i++){
        sum += arr[i];
  
    }
    avg = sum/size;
   
   return avg;
}    
  
/***************************************Mode**************************************************
 * Purpose: Mean of array  
 * Input: *table, size
 * Output: mean
 * 
 
 ***********************************************************************************************/
float  mode (int *table, int size){
    
    float avg = 0.0f, sum = 0.0f;
    
  
    for (int i = 0; i<size; i++){
        sum += table[i]; //Adding all the numbers together
         // cout<<"Array = "<<table[i]; //For diagonostics 
    }
    avg = sum/size;
   
   return avg;
}    

/***************************************Max Frequancy**************************************************
 * Purpose: Mean of array  
 * Input: *table, size
 * Output: mean
 * 
 
 ***********************************************************************************************/
//int maxFreq (int *arr, int size){
//    int max = 0, count = 1;
//    
//    for(int i =0; i <size-1; i++){
//        if (arr[i] == arr[i+1])count++;
//        else if (max < count){
//            max = count;
//            count = 1;
//        }
//    }
////    return (max<count?count:max);
//    if(max<count) return count;
//    
//    else return max;
//    
//}
/***************************************n Modes**************************************************
 * Purpose: Mean of array  
 * Input: *table, size
 * Output: mean
 * 
 
 ***********************************************************************************************/

//int nModes(int *arr, int size){
//    int maxF = maxFreq(arr, size); //Function call to fill max f
//    int count = 1;
//    int num=0;
//     for(int i =0; i <size-1; i++){
//        if (arr[i] == arr[i+1])count++;
//        else if (maxF == count){
//            num++;
//            count = 1; //Reset counter
//        }
//    }
//    if(maxF == count)num++;
//    return num;
//    
//}

//int *Modes(int *arr, int size){
//    int *marr = new int[nModes(arr, size)];
//    int count=1;
//    int j=0;
//    for(int i=0;i<size-1;i++){
//        if(arr[i]==arr[i+1])count++;
//        else if(maxFreq(arr,size)==count){
//            marr[j]=arr[i];
//            count=1;
//            j++;
//        }
//    }
//    if(count==maxFreq(arr,size))marr[j]=arr[size-1];
//    return marr;
//}
statsResult *avgMedMode(int *arr,int size){
    sort(arr, size); //Calling sort fucntion
    int count=1; //Counter 
    float sum = 0.0;
    statsResult *obj = new statsResult; //new pointer to stats results
    obj->nModes=0; //Setting number of modes to 
    
    //avg = ?
        
    
  
    for (int i = 0; i<size-1; i++){ //Avg of all numbers
        sum += arr[i];
  
    }
    obj->avg = sum/size; //Storing in structure
   
    //median
    for(int i =0; i <size-1; i++){
        if (arr[i] == arr[i+1])count++; //Incease counter 
        else if (obj.maxFreq < count){
            obj.maxFreq = count;
            count = 1;
        }
    }
    if(count>obj.maxFreq)obj.maxFreq=count; //if last number in sequence is higher freqancy of all the rest
   count=1; //reset counter 
   
   //Counting modes
    for(int i=0;i<size-1;i++){
        if (arr[i] == arr[i+1])count++;
        else if (obj.maxFreq == count){//The two no longer match asses freqancy
            obj->nModes++; // add to amount of modes
            count = 1; //reset counter
        }
    }
   if(count==obj->nModes)obj->nModes++; //one last check
   
   count=1; //reset counter
   int j=0;
   obj->mode = new int[obj->nModes];
   for(int i=0;i<size-1;i++){
       if(arr[i]==arr[i+1])count++;
       else if(obj->maxFreq==count){
           obj->mode[j]=arr[i];
           j++;
           count=1;
       }
   }
   if(count==obj->maxFreq)obj->mode[j]=arr[size-1];
    
    
    return obj;
}