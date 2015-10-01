/* 
 File:   Prob 12.cpp
 Author: Jonathan Balisky
 Created on September 9, 2015, 10:03 aM
 Purpose:  Display Total sales and tax
 */

//Library iostream and iomanip for formatting the output
#include <iomanip>
#include <iostream>
using namespace std;

//Global const
const int SIZE = 18;

int main(int argc, char** argv ) {
	
	// Local variables
	char mnth[SIZE]; //Month
	int year; //Year
	float totClld; //Total Collected 
	float sales; //Sales 
	float cST; //Country sales tax
	float sST; //State sale 
	float tST; //Total sales tax
	
	//Asking for the amount in dollars + Formatting output
	cout<<setprecision(2)<<showpoint<<fixed;
	cout<<"Please enter year, hit enter, then month: \n";
	cin>>year>>mnth;
	cout<<"Enter the amount total of cash collected: \n";
	cin>>totClld;
	
	
	//Calculations
	
	sales = totClld*1.06;//Total sales without tax
	cST = sales*.02;//County sales tax
	sST = sales*.04;//State sales tax
	tST = cST+sST; //Total sales tax
	
	//Output results
	cout<<"\nYear: "<<year<<"\nMonth: "<<mnth<<endl;
	cout<<"--------------- \n";
	cout<<"Total Collected: "<<setw(8)<<"$ "<<totClld<<endl;
	cout<<"Sales: "<<setw(18)<<"$ "<<sales<<endl;
	cout<<"County Sales Tax: "<<setw(7)<<"$ "<<cST<<endl;
	cout<<"State Sales Tax: "<<setw(8)<<"$ "<<sST<<endl;
	cout<<"Total Sales Tax: "<<setw(8)<<"$ "<<tST<<endl;
	

	//end
	
	return 0;
}