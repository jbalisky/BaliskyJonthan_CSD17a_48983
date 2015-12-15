//Jonathan Balisky
//October 26th, 2015
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

        struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};


using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void sort(int *, int);
float mean(int *, int);
statsResult *avgMedMode(int *,int);
void print (statsResult *, int);
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        
        struct Customer{
    string accNbr; ///Customer's account number
    float checks; ///How many checks were written
    float deposits; ///Amount of deposits
    float balance ; //Customer's balance
};

    //Variables 

    float temp; //Temp holder 
    float pent = 15.00; //Penalty for overdraft
    string exit; //exit sentinal
       Customer cstmr; //Variable for structure 
    Customer *nPtr = &cstmr;//Pointer to numbers


    nPtr->balance = 0;
    nPtr->checks = 0;
    nPtr->deposits =0;
    cin.ignore();
            do {
                cout << "Please input 5 digit customer number: ";

                getline(cin, cstmr.accNbr);
            } while (cstmr.accNbr.length() != 5); // User did not enter 5 digits
do{ //Adding all the debits for the account
    cout<< "Please enter the amount of the check you have written then press enter. \n"
        <<"When you are done type -1. Enter now:";
    cin>>temp;
    if (temp >0)cstmr.checks += (-1*temp);  //Not an exit vaule add
   // cout<<"Cstmer checks "<<cstmr.checks<<endl; //Diagnostics
}while(temp >0);          
temp = 0;
do{ //Adding all the debits for the account
    cout<< "Please enter deposit amounts for this month press enter. \n"
        <<"When you are done type -1.\n Enter now:";
    cin>>temp;
    if (temp >0)cstmr.deposits += temp;  //Not an exit vaule add
   // cout<<"Cstmer deposits "<<cstmr.deposits<<endl;// Diagnostics
}while(temp >0);          
     
cstmr.balance += (cstmr.deposits + cstmr.checks);

if (cstmr.balance >= 0){
    cout<<setprecision(2)<<fixed<<"For customer: "<<cstmr.accNbr<<".\n  There account balance "
        <<"including all deposits and withdraws is: $"<<cstmr.balance;
}
else {
    cstmr.balance -= pent;
    cout<<setprecision(2)<<fixed<<"Ouch!! Its seems you overdrafted.\n"
        <<"Because you dont have any money we are going to take away more! :D \n"
        <<"Your new balance including the fee of $-"<<pent<<" is $"<<cstmr.balance<<endl
        <<"Your customer id is "<<cstmr.accNbr<<". \n";    
}


}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        
struct Worker{
    string emplyNm; ///Worker's name
    float hours; ///How many checks were written
    float hrPay; ///Hourly pay
    float earned; //Worker's earned
    };
             
            //Variables 

    float temp; //Temp holder 
    int num;//number of employees
    string exitV;
    //Worker wPtr[i]; //Variable for structure 
    Worker *wPtr;//Pointer to numbers
    
do{    
    cout<<"\nHow many employees would you like to enter: ";
    cin>>num;
    cin.ignore();
    
     wPtr = new Worker[num];
     
    
     
     
     for(int i=0;i<num;i++){
                    do {
                        cout << "Please input  Workers #"<<i+1<<" name: ";
                        getline(cin, wPtr[i].emplyNm);
//                        cout<<wPtr[i].emplyNm.length()<<endl;
                    } while (wPtr[i].emplyNm.length() < 1); // User did not enter 5 digits
         //Taking in the hours
        do{
            cout<< "Please enter the amount of hours worked by "<<wPtr[i].emplyNm
                    <<" : ";
            cin>>wPtr[i].hours;
          }while(wPtr[i].hours < 0); ///For checking correct value
        cout<<"Employee hours "<<wPtr[i].hours<<endl; //Diagnostics

        temp = 0;
         //Pay rate
        do{
            cout<< "Please enter the hourly rate for "<<wPtr[i].emplyNm<<": ";

            cin>>wPtr[i].hrPay;
            cin.ignore();
        }while(wPtr[i].hrPay < 0);
            cout<<"Employee rate "<<wPtr[i].hrPay<<endl;// Diagnostics
     }


     for(int i = 0; i<num; i++){ // Calculating the hours! 
        if (wPtr[i].hours >= 0 && wPtr[i].hrPay >= 0){

            cout<<setprecision(2)<<showpoint<<fixed;

            if(wPtr[i].hours <= 40){
                //Calculations 
                wPtr[i].earned = wPtr[i].hours*wPtr[i].hrPay; //amount to be payed
             }

            else if (wPtr[i].hours >40 && wPtr[i].hours < 50){//Time an a half
                temp =  wPtr[i].hours;
                wPtr[i].earned = (40)*wPtr[i].hrPay ; //First 40 hours
                temp -= 40.00;
                temp *= 2.0; //Time and a half over 40 hours 
                wPtr[i].earned += (temp*wPtr[i].hrPay);// amount to be payed
            }
            else{ //All time over 50 is triple time
                temp = wPtr[i].hours;   //51
                wPtr[i].earned =40*wPtr[i].hrPay; //
                wPtr[i].earned += ((10*2)*wPtr[i].hrPay);   //double pay
                temp -= 50;
                temp *= 3; //twice the hours 
                wPtr[i].earned += (temp*wPtr[i].hrPay);// amount to be payed
            }
            
           cout<<endl<<wPtr[i].emplyNm<<" worked a total of "<<wPtr[i].hours
                  <<" and have earned a total of $"<<wPtr[i].earned<<endl<<endl;


        }
        else cout<<"\nYou entered an invalid value for employee: \n"<<wPtr;
     }
    
        delete [] wPtr;
        do{
            cout<<"Would you like to exit the program?\n If so enter 'Y':";
            getline(cin, exitV);   
        }while(exitV.length() != 1);
    }while(exitV[0] != 'Y' && exitV[0] !='y');

}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        

        
    //Variables 

    
    int *table;//Table for numbers
    int size; //Size of array
    statsResult *sPtr; 
    

    
    
    
    
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
    obj->avg=0;
    obj->maxFreq = 0;
    obj->median =0;
    
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

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        
        
    //Variables 

    string numbr; //user input
    string exit; //exit sentinal
    char temp; //for swapping
    bool check = false;
   
    cout<<"Type 'E' for encrypting or 'D' for decrypting: ";
    cin>>temp;
    cin.ignore();
    
    if(temp == 'E' || temp == 'e'){
        do {
            cout << "Please input 4 digit number to be encrypted : ";

            getline(cin, numbr);
        } while (numbr.length() != 4); // User did not enter 5 digits

        for(int i = 0; i< 4; i++){ //encrypting
           // cout<<"Before. numbr["<<i<<"]: "<<numbr[i]<<endl;
            if(numbr[i] <51 && numbr[i] > 47)numbr[i] += 5;
            else if(numbr[i] >= 51 && numbr[i] <= 55)numbr[i] -= 3;
            else {
                cout<<"You entered and incorrect number for numbr["<<i<<"]."<<endl;
                check = true;
            }
           // cout<<"After. numbr["<<i<<"]: "<<numbr[i]<<endl;
        }
        //swap
        temp=numbr[0];
        numbr[0] = numbr[1];
        numbr[1] = temp;
        temp=numbr[2];
        numbr[2] = numbr[3];
        numbr[3] = temp;
        if (check == false){
            cout<<"\nEncrypted numbers: ";

            for(int i = 0; i < 4; i++){
                cout<<numbr[i];
            }
        }
        else cout<<"Exiting now...";
    }
    else if(temp == 'D' || temp == 'd'){
        do {
            cout << "Please input 4 digit number to be decrypted : ";

            getline(cin, numbr);
        } while (numbr.length() != 4); // User did not enter 5 digits

        for(int i = 0; i< 4; i++){ //encrypting
           // cout<<"Before. numbr["<<i<<"]: "<<numbr[i]<<endl;
            if(numbr[i] <53 && numbr[i] > 47)numbr[i] += 3;
            else if(numbr[i] >= 53 && numbr[i] <= 55)numbr[i] -= 5;
            else {
                cout<<"You entered and incorrect number for numbr["<<i<<"]."<<endl;
                check = true;
            }
           // cout<<"After. numbr["<<i<<"]: "<<numbr[i]<<endl;
        }
        //swap
        temp=numbr[0];
        numbr[0] = numbr[1];
        numbr[1] = temp;
        temp=numbr[2];
        numbr[2] = numbr[3];
        numbr[3] = temp;

   if (check == false){
            cout<<"\nEncrypted numbers: ";

            for(int i = 0; i < 4; i++){
                cout<<numbr[i];
            }
        }
        else cout<<"Exiting now...";  
    }
    else cout<<"You did not enter a 'D' or an 'E' "<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        
         //Variables 
    cout<<"Each is the max factorial that can be held by that data type \n"
            " char:5! \n Unsigned char:5! \n short:7! \n Unsigned short:8! \n"
            " int:12! \n Unsigned int:12! \n long:12! \n Unsigned long:12! \n"
            " float:34! \n double:170! \n";
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        cout<<"2.125 in Binary: 10.001 Octal: 2.1 Hex: 2.2\n "
                <<".06640625 in binary: .00010001 Octal: .042"
                <<" hex: .11\n"
                <<"-2.124 in 8 digit hex 4 byte float specification: BC000002\n"
                <<".06640625 in 8 digit hex 4 byte float specification:  440000FD\n"
                <<"46666601 Float rep into decimal number: 1.099998489\n"
                <<"46666602 Float rep into decimal number: 10.6999970078\n"
                <<"B9999AFE Float rep into decimal number: .068749994\n";
        
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}