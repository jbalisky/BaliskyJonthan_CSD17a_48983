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
    int *answer , guess; //Answer and guess 
    short xs, os; //Correct prostion and correct number
    char *sAnswer;
    bool *match; //Array for matches 
public:
    Game (int);
    void setUserG(string);
    void setLevel(int );
    bool validate ();
     ~Game();
};


#endif	/* GAME_H */

