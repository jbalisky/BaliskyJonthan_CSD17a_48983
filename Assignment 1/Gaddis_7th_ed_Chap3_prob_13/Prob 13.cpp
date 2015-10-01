/* 
 File:   Prob 13.cpp
 Author: Jonathan Balisky
 Created on July 5, 2015, 5:03 PM
 Purpose:  Display Total property tax
 */

//Library iostream and iomanip for formatting the output
#include <iomanip>
#include <iostream>
using namespace std;

//Global const none

int main(int argc, char** argv ) {
	
	// Local variables
	unsigned int lndVle; //Land values
	unsigned int asVle; //Assessment Value 
	float propTax = .64f; //Property tax per $100
	float totTax; //Total property tax
	
	
	//Asking for the amount in dollars + Formatting output
	cout<<setprecision(2)<<showpoint<<fixed;
	cout<<"Please enter the actual value of the land: \n";
	cin>>lndVle;

	
	
	//Calculations
	
	asVle = lndVle*.6;//Assessment value is 60%
	totTax = (asVle/100)*propTax;//Tax to be payed

	
	//Output results
	cout<<"The assessment value of your property: $"<<asVle<<endl;
	cout<<"At "<<propTax<<" cents per $100 dollars your tax will be: $"<<totTax<<endl;


	//end
	
	return 0;
}