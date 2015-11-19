/* 
 * File:   IsValid.h
 * Author: Jonathan
 *
 * Created on November 19, 2015, 9:57 AM
 */


#ifndef ISVALID_H
#define	ISVALID_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class IsValid{
private:
    string temp;
    int level;
public:
    void setUserG(string g);
    void setLevel(int l);
    bool validate ();
};



#endif	/* ISVALID_H */

