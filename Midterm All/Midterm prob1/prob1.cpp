/* 
 File:   Game.cpp
 Author: Jonathan Balisky
 Created on July 25, 2015, 9:18 pM
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
struct Customer{
    string accNbr; ///Customer's account number
    float checks = 0; ///How many checks were written
    float deposits =0; ///Amount of deposits
    float balance = 0; //Customer's balance
};


//Global 

int main(int argc, char** argv) {

    //Variables 

    float temp; //Temp holder 
    float pent = 15.00; //Penalty for overdraft
    string exit; //exit sentinal
       Customer cstmr; //Variable for structure 
    Customer *nPtr = &cstmr;//Pointer to numbers


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
    cout<<setprecision(2)<<fixed<<"Ouch!! Its seems you overdraftd.\n"
        <<"Because you dont have any money we are going to take away more! :D \n"
        <<"Your new balance including the fee of $-"<<pent<<" is $"<<cstmr.balance<<endl
        <<"Your customer id is "<<cstmr.accNbr<<". \n";    
}


    return 0;
}

