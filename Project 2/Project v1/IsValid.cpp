/* 
 * File:   IsValid.cpp
 * Author: Juanathan Balisky
 * Created on 11,19,2015
 * Purpose: Implementation isValid
 */

//User Library for the Specification
#include "IsValid.h"

void IsValid::setUserG(string g){
    temp = g;
   // cout<<"IsValid was called and string was set"<<endl;
}

void IsValid::setLevel(int l){
    level = l;
   // cout<<"IsValid was Called and Level was set"<<endl;
}

/***************************************isvalid**************************************************
 * Purpose: To check whether or not the user entered 3 numbers 
 * Input: usrG, level
 * Output: True or false
 
 ***********************************************************************************************/

bool IsValid::validate(){
    // cout<<"Call isvalid."<<endl; //For diagonostics
    if (temp.length() != level) {
        cout << "Please enter " << level << " numbers." << endl;
        return false;
    } else {
        for (int i = 0; i < level; i++) {
            if (temp[i] < 48 || temp[i] > 57) {
                cout << "Number not entered" << endl;
                return false;
            }
        }
        // cout<<"number valid"<<endl;//For diagonostics
        return true;
    }


}