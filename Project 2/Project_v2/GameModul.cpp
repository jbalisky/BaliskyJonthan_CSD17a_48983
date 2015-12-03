/* 
 * File:   IsValid.cpp
 * Author: Juanathan Balisky
 * Created on 11,19,2015
 * Purpose: Implementation isValid
 */

#include"Game.h"

Game::Game(int level){
    char **table;
    answer = new int [level]; //users answer
   sAnswer =  new char [level];
   match = new bool [level]; //which colums are matched 
    
    

 
    guess = 9;

    for (int i = 0; i < level; i++) {
        answer[i] = rand() % 10; //creating answer from 0-9
        sAnswer [i] = answer[i] + 48; //ascii equivalent to numbers
        match[i] = false; //Set all to false

        //cout<<"answer = "<<answer[i]; //For diagonostics 
    }



    //    answer[0]=3;
    //    answer[1]=3;
    //    answer[2]=4;
    //    

    table = new char *[guess]; //Creating 2 d dynamic array
    for (int i = 0; i < guess; i++) { //
        table[i] = new char[level];
    }
    // cout<<endl;
    xs = 0;
    os = 0;

    for (int i = 0; i < guess; i++) {//Filling the array with empty spaces
        for (int j = 0; j < level; j++) {
            table[i][j] = ' ';
        }
    }

 
}
