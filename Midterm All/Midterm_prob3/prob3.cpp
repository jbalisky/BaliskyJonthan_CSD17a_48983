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

void sort(int *, int);
float mean(int *, int);
statsResult *avgMedMode(int *,int);
void print (statsResult *, int);

int main(int argc, char** argv) {

    //Variables 

    
    int *table;//Table for numbers
    int size; //Size of array
    statsResult *sPtr; 
    
    
    srand(time(0)); //Setting the time seed
    
    cout<<"Input size of array ";
    cin>>size; //Input the size of the array
    
    table = new int[size]; //alocating size for the array
    
    for(int i = 0; i <size; i++){
        cout<<"Please enter number for location table["<<i<<"]: ";
        cin>>table[i];
    }

  sPtr =  avgMedMode(table, size);

  print(sPtr, size);
    
//    for(int i =0; i<size; i++){
//        cout<<table[i]<<" /n";
//        if (i%10 == 0) cout<<endl;
//    }
// 
   delete [] sPtr->mode;
   delete [] sPtr;//
    delete [] table; //Cleaning up
    return 0;
}
/***************************************Print**************************************************
 * Purpose: Printing the results  
 * Input: *sPtr size
 * Output:
 none
 
 ***********************************************************************************************/
void  print (statsResult *sPtr, int size){
    
    
    cout<<"The avg:"<<sPtr->avg<<"\n median:"<<sPtr->median
            <<"\n Max Freq:"<<sPtr->maxFreq<<"\n number of modes:"<<sPtr->nModes<<endl;
    //for(int i=0;i<size;i++)
    cout<<"Modes: ";
    for(int i = 0; i <sPtr->nModes; i++){
        cout<<sPtr->mode[i]<<" ";
    }
    cout<<endl;
    
//   int size = 10;
   
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
        cout<<table[i]<<" ";
        }
    cout<<endl;
       
 
}

/***************************************avgMedMode**************************************************
 * Purpose: Mean, avg, mode of array  
 * Input: *arr, size
 * Output: pointer to structure
 * 
 
 ***********************************************************************************************/
statsResult *avgMedMode(int *arr,int size){
    sort(arr, size); //Calling sort fucntion
    int count=1; //Counter 
    float sum = 0.0;
    statsResult *obj = new statsResult; //new pointer to stats results
    obj->nModes=0; //Setting number of modes to 
    
    //avg
        
     
    for (int i = 0; i<size-1; i++){ //Avg of all numbers
        sum += arr[i];
  
    }
    obj->avg = sum/(size-1); //Storing in structure
   
    //median if even number
    if (size%2 == 0)obj->median= (static_cast<float>(arr[(size-1)/2])+static_cast<float>(arr[size/2]))/2.0;
    //Mediean if odd number
    else obj->median = arr[(size-1)/2];
    
    //max freqancy
    for(int i =0; i <size-1; i++){
        if (arr[i] == arr[i+1])count++; //Incease counter 
        else if (obj->maxFreq < count){
            obj->maxFreq = count;
            count = 1;
        }
    }
    if(count>obj->maxFreq)obj->maxFreq=count; //if last number in sequence is higher freqancy of all the rest
   count=1; //reset counter 
   
   //Counting modes
    for(int i=0;i<size-1;i++){
        if (arr[i] == arr[i+1])count++;
        else if (obj->maxFreq == count){//The two no longer match asses freqancy
            obj->nModes++; // add to amount of modes
            count = 1; //reset counter
        }
    }
   if(count==obj->maxFreq)obj->nModes++; //one last check
   
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