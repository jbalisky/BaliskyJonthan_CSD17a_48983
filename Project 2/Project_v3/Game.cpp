/* 
 * File:   Game.cpp
 * Author: Juanathan Balisky
 * Created on 11,19,2015
 * Purpose: Implementation isValid
 */

#include"Game.h"
//ch 15 inheritance (i spell it right!!!)
//ch 16 template
/**
 * 
 * @param level //see?
 */
Game::Game(int l){
    //you can ask here and delete the level parameter which is level here
    //Game(int level) this level is a para!!!!!
    level = l;
    
    //Dynamicly allocating memory
   answer = new int [level]; //
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
Game::~Game(){
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
////setting level into the private variables
void Game::setLevel(int l){
    level = l;
}
////setting usrG into the private variables
void Game::setUsrG(string uG){
    usrG = uG;
}
//Getting xs 
//need to put the return type at the beginning
//only return var, should be const right?
//just showing him you know the concept
short Game::getXs() const{
    return xs;
}
//Getting os
short Game::getOs() const {
    return os;
}
//Getting the amount of guesses left
//if you only have one line command inside the function, you can put it into head file
//called inline functino  cannot remember how to spell, sth inside the book
int Game::getGuess() const{
    return guess;
}

//getting saved answer
char *Game::getSAns()const{
    return sAnswer;
}