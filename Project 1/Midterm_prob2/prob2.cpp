/* 
 File:   Game.cpp
 Author: Jonathan Balisky
 Created on July 25, 20i5, 9:i8 pM
 Purpose:  Mastermind .  
 */

//Libraries 


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

//User libraries

using namespace std;
//structured data
struct Worker{
    string emplyNm; ///Worker's name
    float hours; ///How many checks were written
    float hrPay; ///Hourly pay
    float earned; //Worker's earned
};

//Functions Prototypes
//char ** prepare(int [], int&, bool[], int, char[], Worker *);
//bool isvalid(string, int );
//void compare(int [], string, bool[], int, Worker *) ;
//void gssHst(string, int, char **, int);
//void sort(char **, int, int );

//Global 

int main(int argc, char** argv) {

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
return 0;
}

    



///***************************************Prepare**************************************************
// * Purpose: Initializing values for the game.  
// * Input: answer, guess, match, level, nPtr
// * Output:
// * table
// 
// ***********************************************************************************************/
//char ** prepare(int answer[], int &guess, bool match[], int level, char sAnswer [],Worker *nPtr) {
//
//    char **table;
//
// 
//    guess = 9;
//
//    for (int i = 0; i < level; i++) {
//        answer[i] = rand() % i0; //creating answer from 0-9
//        sAnswer [i] = answer[i] + 48; //ascii equivalent to numbers
//        match[i] = false; //Set all to false
//
//        //cout<<"answer = "<<answer[i]; //For diagonostics 
//    }
//
//
//
//    //    answer[0]=3;
//    //    answer[i]=3;
//    //    answer[2]=4;
//    //    
//
//    table = new char *[guess]; //Creating 2 d dynamic array
//    for (int i = 0; i < guess; i++) { //
//        table[i] = new char[level];
//    }
//    // cout<<endl;
//    nPtr->xs = 0;
//    nPtr->os = 0;
//
//    for (int i = 0; i < guess; i++) {//Filling the array with empty spaces
//        for (int j = 0; j < level; j++) {
//            table[i][j] = ' ';
//        }
//    }
//
//    return table;
//}
//
///***************************************isvalid**************************************************
// * Purpose: To check whether or not the user entered 3 numbers 
// * Input: usrG, level
// * Output: True or false
// 
// ***********************************************************************************************/
//bool isvalid(string usrG, int level) {
//    // cout<<"Call isvalid."<<endl; //For diagonostics
//    if (usrG.length() != level) {
//        cout << "Please enter " << level << " numbers." << endl;
//        return false;
//    } else {
//        for (int i = 0; i < level; i++) {
//            if (usrG[i] < 48 || usrG[i] > 57) {
//                cout << "Number not entered" << endl;
//                return false;
//            }
//        }
//        // cout<<"number valid"<<endl;//For diagonostics
//        return true;
//    }
//
//}

///***************************************Compare**************************************************
// * Purpose: To compare the user's guess with the answer and return how many 
// * were correct or incorrect. 
// * Input: answer,  usrG, match, level, nPtr
// * Output:none
// 
// ***********************************************************************************************/
//
//void compare(int answer[], string usrG, bool match[], int level, Worker *nPtr) {
//    nPtr->xs = 0;
//    nPtr->os = 0;
//
//    for (int i = 0; i < level; i++) {
//        match[i] = false; //int all values to zero again
//    }
//
//    //Checking for correct numbers in the right position 
//    for (int i = 0; i < level; i++) {
//        if (answer[i] == (usrG[i] - 48)) { //subtracting 48 makes it an integer
//            nPtr->xs++;
//            //cout<<"match["<<i<<"] = true"<<endl;
//            match[i] = true;
//        }
//    }
//    //Checking for os
//    for (int i = 0; i < level; i++) { //i is position of answer
//        for (int j = 0; j < level; j++) { //j is position of usrG(user guess)
//            if (j != i && match[i] == false && answer[i] == usrG[j] - 48) {
//                //    //            cout<<"Match["<<i<<"] = "<<match[i]<<" usrG["<<j<<"] = "<<usrG[j]<<endl
//                //      //                  <<"Answer["<<i<<"] = "<<answer[i]<<endl;
//                nPtr->os++;
//                match[i] = true;
//            }
//        }
//    }
//   
//}
//
///***************************************gssHst**************************************************
// * Purpose: To keep a record of the the user's guesses  
// * Input: usrG, counter, table
// * Output:none
// 
// ***********************************************************************************************/
//void gssHst(string usrG, int counter, char **table, int level) {
//    for (int i = 0; i < level; i++) {
//        table[counter][i] = usrG[i];
//    }
//    //    cout<<"\n"; //For Diagnositics 
//    //    for(int i=0;i<9;i++){
//    //        for(int j=0;j<level;j++){
//    //            cout<<table[i][j];
//    //        }
//    //        cout<<"\n";
//    //    }
//    //    cout<<"\n\n\n\n";
//}
//
///***************************************Sort***************************************************
// * Purpose: To Sort all the user guesses to show I can do it...so HA! Using a bubble sort
// * Input: table, counter, level
// * Output:none
// 
// ***********************************************************************************************/
//void sort(char **table, int counter, int level) {
//
//    bool swap = false; //For the bubble swap function
//    int indx = 0; //Second index location for table       
//
//    cout << "Unsorted answers from you!!" << endl;
//    for (int i = 0; i < counter; i++) {
//        for (int j = 0; j < level; j++) {
//            cout << table[i][j];
//        }
//        cout << endl;
//    }
//
//    do {
//        swap = false;
//
//        for (int i = 0; i < counter - i; i++) { //counter -i because bubble swap is always columns - i
//            indx = 0;
//            while (table[i][indx] == table[i + i][indx] && indx < level)indx++; //Checking to see if current
//            //index is equal then going to next location if they 
//            //are equal. 
//            if (table[i][indx] > table[i + i][indx]) { //If that row and col. not equal 
//                //then check if first is larger if it is then swap all numbers
//                //cout << endl << "i = " << i << endl;
//                for (int j = 0; j < level; j++) { //Swapping each 2 rows and their respective columns until all the rows are swapped
//                   // cout << "Table[i] = " << table[i][j] << "table[i+i] = " << table[i + i][j] << endl; //For diagnostics
//                    table [i][j] = table [i][j]^table[i + i][j]; //in place swap. to hopefully make Dr lehr happy so he give me extra credit
//                    table [i + i][j] = table [i][j]^table[i + i][j];
//                    table [i][j] = table [i][j]^table[i + i][j];
//                }
//                swap = true;
//            }
//
//        }
//    } while (swap == true);
//
//    cout << "Sorted answers via bubble sorts !!" << endl;
//    for (int i = 0; i < counter; i++) {
//        for (int j = 0; j < level; j++) {
//            cout << table[i][j];
//        }
//        cout << endl;
//    }
//
//
//
//
//}