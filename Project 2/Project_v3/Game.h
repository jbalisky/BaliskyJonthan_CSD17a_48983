/* 
 * File:   Game.h
 * Author: Jonathan
 * Purpose: changing  game to moduls 
 * Created on November 21, 2015, 2:47 PM
 */

#ifndef GAME_H
#define	GAME_H
#include"IsValid.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game{
private:
    int *answer; //randomly gen. answer
    int guess; // how many guesses the user has left
    int level; //what difficultly the player selected 
    int counter; //Which guess number the user is on
    string usrG; //the user's guess 
    short xs, os; //Correct prostion and correct number
    char *sAnswer;
    char **table; //Table for answers
    bool *match; //Array for matches 
    
public:
    Game (int);
    void setUserG(string);
    void setLevel(int );
    short getXs();
    short getOs();
    int getGuess();
    void compare() {
      
        //Reseting vaules = 0
      xs = 0;
      os = 0;
        
    for (int i = 0; i < level; i++) {
            match[i] = false; //int all values to zero again
        }

        //Checking for correct numbers in the right position 
        for (int i = 0; i < level; i++) {
            if (answer[i] == (usrG[i] - 48)) { //subtracting 48 makes it an integer
                xs++;
                //cout<<"match["<<i<<"] = true"<<endl;
                match[i] = true;
            }
        }
        //Checking for os
        for (int i = 0; i < level; i++) { //i is position of answer
            for (int j = 0; j < level; j++) { //j is position of usrG(user guess)
                if (j != i && match[i] == false && answer[i] == usrG[j] - 48) {
                    //    //            cout<<"Match["<<i<<"] = "<<match[i]<<" usrG["<<j<<"] = "<<usrG[j]<<endl
                    //      //                  <<"Answer["<<i<<"] = "<<answer[i]<<endl;
                    os++;
                    match[i] = true;
                }
            }
        }
      //user has used a guess
      guess--
    }
    void gssHst(){
        
      for (int i = 0; i < level; i++) {
        table[counter][i] = usrG[i];
    }
      counter++;
}
    void sort(){
    bool swap = false; //For the bubble swap function
    int indx = 0; //Second index location for table       

    cout << "Unsorted answers from you!!" << endl;
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < level; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }

    do {
        swap = false;

        for (int i = 0; i < counter - 1; i++) { //counter -1 because can swap the last one with the one after
            indx = 0;
            while (table[i][indx] == table[i + 1][indx] && indx < level)indx++; //Checking to see if current
            //index is equal then going to next location if they 
            //are equal. 
            if (table[i][indx] > table[i + 1][indx]) { //If that row and col. not equal 
                //then check if first is larger if it is then swap all numbers
                //cout << endl << "i = " << i << endl;
                for (int j = 0; j < level; j++) { //Swapping each 2 rows and their respective columns until all the rows are swapped
                   // cout << "Table[i] = " << table[i][j] << "table[i+1] = " << table[i + 1][j] << endl; //For diagnostics
                    table [i][j] = table [i][j]^table[i + 1][j]; //in place swap. to hopefully make Dr lehr happy so he give me extra credit
                    table [i + 1][j] = table [i][j]^table[i + 1][j];
                    table [i][j] = table [i][j]^table[i + 1][j];
                }
                swap = true;
            }

        }
    } while (swap == true);

    cout << "Sorted answers via bubble sorts !!" << endl;
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < level; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
        
    }
    bool validate ();
    
     ~Game();
};


#endif	/* GAME_H */

