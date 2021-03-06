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
    bool *aMatch; //Array for answer matches
    bool *gMatch; //Array for the guess matches
    
public:
    //only constructor , one para
    Game (int);
    short getXs() const;
    short getOs() const;
    int getGuess() const;
    char * getSAns() const;
    void setLevel(int);
    void setUsrG(string);
    void compare() {
        
       // cout<<"\n Compare ran \n";
      
        //Reseting vaules = 0
      xs = 0;
      os = 0;
        
    for (int i = 0; i < level; i++) {
            aMatch[i] = false; //int all values to zero again
            gMatch[i] = false;
                      //    cout<<"\n False int. ran \n";
        }



        //Checking for correct numbers in the right position 
        for (int i = 0; i < level; i++) {
            // cout<<"usrG["<<i<<"] =" <<usrG[i]<<endl;
            if (answer[i] == (usrG[i] - 48)) { //subtracting 48 makes it an integer
                xs++;
                cout<<"aMatch["<<i<<"] = true"<<endl;
                aMatch[i] = true;
                gMatch[i] = true;
            }
        }
        //Checking for os
        for (int i = 0; i < level; i++) { //i is position of answer
            cout<<"answer["<<i<<"] =" <<answer[i]<<endl<<"aMatch["<<i<<"] = "<<aMatch[i]<<endl;
            for (int j = 0; j < level; j++) { //j is position of usrG(user guess)
                if (j != i && aMatch[i] == false && gMatch[j] == false && answer[i] == usrG[j] - 48) {
                                cout<<" usrG["<<j<<"] = "<<usrG[j]<<endl
                                        <<"gMatch["<<i<<"] = "<<gMatch[j]<<endl;
                    os++;
                    cout<<"os = "<<os<<endl;
                    aMatch[i] = true;
                    gMatch[j] = true;
                    
                    
                }
                
            }
        }
      //user has used a guess
      guess--;
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

