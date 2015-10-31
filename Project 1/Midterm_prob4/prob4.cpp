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


//Functions Prototypes

//Global 

int main(int argc, char** argv) {

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
    return 0;
}

