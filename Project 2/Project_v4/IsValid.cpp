/* 
 * File:   IsValid.cpp
 * Author: Juanathan Balisky
 * Created on 11,19,2015
 * Purpose: Implementation isValid
 */

//User Library for the Specification
#include "IsValid.h"

void IsValid::setUserG(string usrG){
    
    cout<<this->usrG<<endl;
   // cout<<"IsValid was called and string was set"<<endl;
}

void IsValid::setLevel(int l){
    level = l;
   // cout<<"IsValid was Called and Level was set"<<endl;
}

/***************************************isvalid**************************************************
 * Purpose: To check whether or not the user entered correct amount of numbers 
 * Input: usrG, level
 * Output: True or false
 
 ***********************************************************************************************/

bool IsValid::validate(string a){
    // cout<<"Call isvalid."<<endl; //For diagonostics
//    for(int i = 0; i<level; i++){
//        cout<<"usrG["<<i<<"] = "<< usrG[i]<<endl;
//    }
    if (a.length() != level) {
        cout << "Please enter " << level << " numbers." << endl;
        return false;
    } else {
        for (int i = 0; i < level; i++) {
            if (a[i] < 48 || a[i] > 57) {
                cout << "Please enter numbers and numbers only." << endl;
                return false;
            }
        }
        // cout<<"number valid"<<endl;//For diagonostics
        return true;
    }


}