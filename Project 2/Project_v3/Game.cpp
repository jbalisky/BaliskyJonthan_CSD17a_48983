/* 
 * File:   IsValid.cpp
 * Author: Juanathan Balisky
 * Created on 11,19,2015
 * Purpose: Implementation isValid
 */

#include"Game.h"

Game::Game(int level){
    //Dynamicly allocating memory
    answer = new int [level]; //
   sAnswer =  new char [level];
   match = new bool [level]; //which collums are matched 
   
    
//Setting default vaules
    xs = 0; 
    os = 0;
    guess = 9;
    counter = 0;

    for (int i = 0; i < level; i++) {
        answer[i] = rand() % 10; //creating answer from 0-9
        sAnswer [i] = answer[i] + 48; //ascii equivalent to numbers
        match[i] = false; //Set all to false

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
Game::~Game(){
    //if Game was activated and answer was actually created then delete.
    if(answer[] != NULL){
        delete[] answer; //
        delete[] guess;
        delete[] sAnswer;
        delete[] match;
        //Deleting 2d array
      for (int i = 0; i<9; i++){
          delete table[i];
      } 
        delete[] table;
    }
}
//setting level into the private variables
Game::setLevel(int l){
    level = l;
}
//setting usrG into the private variables
Game::setUserG(string uG){
    usrG = uG;
}
//Getting xs 
Game::getXs(){
    return xs;
}
//Getting os
Game::getOs(){
    return os;
}
//Getting the amount of guesses left
Game::getGuess(){
    return guess;
}