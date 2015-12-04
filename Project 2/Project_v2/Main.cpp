/* 
 File:   Game.cpp
 Author: Jonathan Balisky
 Created on July 25, 2015, 9:18 pM
 Purpose:  Mastermind .  
 */

//Libraries 


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

//User libraries
#include"IsValid.h"
#include "Game.h"

using namespace std;
//structured data
struct Numbers{
    int xs; //How many x's
    short os; //How many o'x
};

//Functions Prototypes
char ** prepare(int [], int&, bool[], int, char[], Numbers *);
bool isvalid(string, int );
void compare(int [], string, bool[], int, Numbers *) ;
void gssHst(string, int, char **, int);
void sort(char **, int, int );

//Global 

int main(int argc, char** argv) {

    const int SIZE = 4;
    //Variables 

    IsValid iV; //Is valid variable 
    Game game; //Game varriable 
    int level = 3; //Difficulty  of game
    string temp; //For the file output
    fstream inOut; // for file stream
    string usrG; //The users guess or input
//    int answer[SIZE]; //number of pin
//    char sAnswer[SIZE]; //Answer 
//    bool match[SIZE]; //Which numbers are matched

//    int guess; //How many guess the user had guessed 
//    char **table; //Table of the user guesses 
//    int counter = 0; //Row counter for table
//    Numbers nmbr; //Variable for structure 
//    Numbers *nPtr = &nmbr;//Pointer to numbers

    srand(time(0)); //setting time seed
    do {

        counter = 0;



        // cout<<"Call prepare."<<endl;//For diagonostics
        inOut.open("instructions.dat", ios::in);
        if (inOut.is_open()) {
            while (getline(inOut, temp)) {
                cout << temp;
            }
            inOut.close();
        } else {
            cout << "Instructions failed to open" << endl;

        }
        do {
            do {
                cout << "What difficulty would you like to play? 1 for Easy or 2 for normal: ";

                getline(cin, temp);
            } while (temp.length() != 1); // User did not enter 1 digit
        } while (temp[0] != 49 && temp[0] != 50); // User did not enter 1 or 2

        if (temp[0] == 49) { //Level is easy
            level = 3;
        } else { //User selected hard level
            level = 4;
        }
        iV.setLevel(level);//setting the level (Maybe this should be put into a class function?)
        game.setLevel(level);//Setting the level

       // table = prepare(answer, guess, match, level, sAnswer, nPtr); //Initialize (shouldnt need this)

        // cout<<"Call prepare."<<endl;//For diagonostics
        //   //Out Put answer to a file
        //       inOut.open("Answer.dat", ios::out);
        //       
        //       if(inOut.is_open()){
        //       
        //           for (int i = 0; i<level; i++){
        //            inOut<<answer[i];
        //            }
        //           inOut.close();
        //       }
        //       else{
        //           cout<<"Failed to write answer to file";
        //       }
        //      
        //Output answer as Binary
        inOut.open("Answer.dat", ios::out | ios::binary | ios::app);

        if (inOut.is_open()) {
            inOut<<endl;
            inOut.write(sAnswer, sizeof (sAnswer));
            inOut.close();
        }
        else {
            cout << "Failed to write answer to file" << endl;
        }

        //      for(int i=0;i<3;i++){
        //cout<<answer[i]; //For diagonostics
        //      }

        do {
            do {
                cout << "Input your guess: " << endl; //User enter guess
                getline(cin, usrG); //This should be removed And simply call a class function to do this
                iV.setUserG(usrG); //Setting user guess in the is valid...
                game.setUserG(usrG);//Setting user guess in the Game class
                //cin.ignore();

            } while (iV.validate() == false); //Loop until user enters valid answer

            game.gssHst(); //Storing the user's guess
           // counter++; //gssHst Ran
            game.compare();
          //compare(answer, usrG, match, level, nPtr);

            cout << "X(s)=" << game.getXs() << endl; //Right numbers in right space
            cout << "O(s)=" << game.getOs() << endl; //How many Correct number but in the incorrect space
            //guess--;
            cout << "Guesses left: " << game.getGuess() << endl;

            
        } while (game.getGuess() > 0 && game.getXs() != level); // Continue if user 
        // has more guesses or has not guess correctly yet

        if (game.getXs() == level) { //user won
            cout << "Congrats you won!" << endl;
        } else { //user lost
            cout << "Sorry but you ran out of guesses. :( " << endl;

        }

        
       // sort(table, counter, level);

        for (int i = 0; i < 9; i++) {
            delete table[i];
        }
        delete[] table;
        do { //Checking for an input of Y or N
            do { //Checking for input over 1 char
                cout << "Play again Y/N?" << endl;
                getline(cin, usrG);
            } while (usrG.length() != 1);
        } while (toupper(usrG[0]) != 89 && toupper(usrG[0]) != 78);
        //}while(usrG[0] > 'Y' || usrG < 'N' || (usrG[0]>'N' && usrG[0]<'Y'));
    } while (toupper(usrG[0]) == 'Y');

    cout << "See you again next time!" << endl;



    return 0;
}

/***************************************Prepare**************************************************
 * Purpose: Initializing values for the game.  
 * Input: answer, guess, match, level, nPtr
 * Output:
 * table
 
 ***********************************************************************************************/
//char ** prepare(int answer[], int &guess, bool match[], 
//        int level, char sAnswer [],Numbers *nPtr) {
//
//    char **table;
//
// 
//    guess = 9;
//
//    for (int i = 0; i < level; i++) {
//        answer[i] = rand() % 10; //creating answer from 0-9
//        sAnswer [i] = answer[i] + 48; //ascii equivalent to numbers
//        match[i] = false; //Set all to false
//
//        //cout<<"answer = "<<answer[i]; //For diagonostics 
//    }
//
//
//
//    //    answer[0]=3;
//    //    answer[1]=3;
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

/***************************************Compare**************************************************
 * Purpose: To compare the user's guess with the answer and return how many 
 * were correct or incorrect. 
 * Input: answer,  usrG, match, level, nPtr
 * Output:none
 
 ***********************************************************************************************/

//void compare(int answer[], string usrG, bool match[], int level, Numbers *nPtr) {
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

/***************************************gssHst**************************************************
 * Purpose: To keep a record of the the user's guesses  
 * Input: usrG, counter, table
 * Output:none
 
 ***********************************************************************************************/
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

/***************************************Sort***************************************************
 * Purpose: To Sort all the user guesses to show I can do it...so HA! Using a bubble sort
 * Input: table, counter, level
 * Output:none
 
 ***********************************************************************************************/
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
//        for (int i = 0; i < counter - 1; i++) { //counter -1 because can swap the last one with the one after
//            indx = 0;
//            while (table[i][indx] == table[i + 1][indx] && indx < level)indx++; //Checking to see if current
//            //index is equal then going to next location if they 
//            //are equal. 
//            if (table[i][indx] > table[i + 1][indx]) { //If that row and col. not equal 
//                //then check if first is larger if it is then swap all numbers
//                //cout << endl << "i = " << i << endl;
//                for (int j = 0; j < level; j++) { //Swapping each 2 rows and their respective columns until all the rows are swapped
//                   // cout << "Table[i] = " << table[i][j] << "table[i+1] = " << table[i + 1][j] << endl; //For diagnostics
//                    table [i][j] = table [i][j]^table[i + 1][j]; //in place swap. to hopefully make Dr lehr happy so he give me extra credit
//                    table [i + 1][j] = table [i][j]^table[i + 1][j];
//                    table [i][j] = table [i][j]^table[i + 1][j];
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