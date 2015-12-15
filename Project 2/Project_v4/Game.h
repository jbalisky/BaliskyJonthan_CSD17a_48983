/* 
 * File:   Game.h
 * Author: Jonathan
 * Purpose: changing  game to moduls 
 * Created on November 21, 2015, 2:47 PM
 */

#ifndef GAME_H
#define	GAME_H
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include "IsValid.h"
using namespace std;
template <class T>
class Game :public IsValid{
private:
    T *answer; //randomly gen. answer
    int guess; // how many guesses the user has left
    int level; //what difficultly the player selected 
    int counter; //Which guess number the user is on
//    string usrG; //the user's guess 
    short xs, os; //Correct prosition and correct number
    char *sAnswer;
    char **table; //Table for answers
    bool *aMatch; //Array for answer matches
    bool *gMatch; //Array for the guess matches
    
public:
    //only constructor , one para
    Game (int level);
    ~Game();
    short getXs() const;
    short getOs() const;
    int getGuess() const;
    char * getSAns() const;
//    void setLevel(int);
//    void setUsrG(string);
     void compare(string usrG) {
        
        cout<<"\n Compare ran \n";
        cout<<usrG<<endl;
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
//                cout<<"aMatch["<<i<<"] = true"<<endl;
                aMatch[i] = true;
                gMatch[i] = true;
            }
        }
//      cout<<"level = "<<level<<endl;
        //Checking for os
        for (int i = 0; i < level; i++) { //i is position of answer
//            cout<<"answer["<<i<<"] =" <<answer[i]<<endl<<"aMatch["<<i<<"] = "<<aMatch[i]<<endl
//                    <<"userG["<<i<<"] = "<<usrG[i]<<endl;
            for (int j = 0; j < level; j++) { //j is position of usrG(user guess)
                if (j != i && aMatch[i] == false && gMatch[j] == false && answer[i] == usrG[j] - 48) {
//                      cout<<" usrG["<<j<<"] = "<<usrG[j]<<endl
//                                        <<"gMatch["<<i<<"] = "<<gMatch[j]<<endl;
                    os++;
//                    cout<<"os = "<<os<<endl;      
                    aMatch[i] = true;
                    gMatch[j] = true;
                    
                    
                }
                
            }
        }
      //user has used a guess
      guess--;
    }
    
    void gssHst(string usrG){
        
        

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
  //  bool validate ();
    
     
};
template <class T>
Game<T>::Game(int level) :IsValid(level){
    
//    setLevel(level);
    //you can ask here and delete the level parameter which is level here
    //Game(int level) this level is a para!!!!!
//    level = l;
    
    //Dynamicly allocating memory
   answer = new T [level]; //
   sAnswer =  new char [level];
   aMatch = new bool [level]; //which collums are answers arematched 
   gMatch = new bool [level]; //which guesses are right but wrong possition
    
//Setting default vaules
    xs = 0; 
    os = 0;
    guess = 9;
    counter = 0;

    for (int i = 0; i < level; i++) {
        answer[i] = rand() % 10; //creating answer from 0-9
        sAnswer [i] = answer[i] + 48; //ascii equivalent to numbers
        aMatch[i] = false; //Set all to false
        gMatch[i] = false; //set all to false

        //cout<<"answer = "<<answer[i]; //For diagonostics 
    }



    //   
    table = new char *[guess]; //Creating 2 d dynamic array
    for (int i = 0; i < guess; i++) { //
        table[i] = new char[level];
    }
    // cout<<endl;
    

    for (int i = 0; i < guess; i++) {//Filling the array with empty spaces
        for (int j = 0; j < level; j++) {
            table[i][j] = ' ';
        }
    }

 
}
//Destructor
template <class T>
Game<T>::~Game(){
    //if Game was activated and answer was actually created then delete.
   // if(answer[0] != NULL){
        delete[] answer; //
        delete[] sAnswer;
        delete[] aMatch;
        delete[] gMatch;
        //Deleting 2d array
      for (int i = 0; i<9; i++){
          delete table[i];
     } 
        delete[] table;
    //}
}
//setting level into the private variables
//void Game<T>::setLevel(int l){
//    level = l;
//}
//setting usrG into the private variables
//void Game<T>::setUsrG(string uG){
//    
//    usrG = uG;
//}
//Getting xs 
//need to put the return type at the beginning
//only return var, should be const right?
//just showing him you know the concept
template <class T>
short Game<T>::getXs() const{
    return xs;
}
//Getting os
template <class T>
short Game<T>::getOs() const {
    return os;
}
//Getting the amount of guesses left
//if you only have one line command inside the function, you can put it into head file
//called inline functino  cannot remember how to spell, sth inside the book
template <class T>
int Game<T>::getGuess() const{
    return guess;
}

//getting saved answer
template <class T>
char *Game<T>::getSAns()const{
    return sAnswer;
}

#endif	/* GAME_H */

