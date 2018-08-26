#include <iostream>
#include <stdlib.h>
#include "CA1H.h"
#include <iomanip> 
#include <math.h>
#include <string>

using namespace std;

void Donor::add(string &firstName, string &lastName, int &age, 
		int &houseNum, string &streetName, string &town, 
		string &zipcode, float &amtDonate){
	cout << "What is the donor's first name?";
	cin >> firstName;
	cout << "What is the donor's last name?";
	cin >> lastName;
	cout << "How old is the donor?";
	cin >> age;
	cout << "What is the house number of the donor?";
	cin >> houseNum;
	cout << "What is the street name of the donor?";
	cin >> streetName;
	cout << "What town does the donor live in?";
	cin >> town;
	cout << "What is the zipcode of the town?";
	cin >> zipcode;
};

void Donor::manage(string &firstName, string &lastName, int &age, 
		int &houseNum, string &streetName, string &town, 
		string &zipcode){
	cout << "What is the donor's first name?";
	cin >> firstName;
	cout << "What is the donor's last name?";
	cin >> lastName;
	cout << "How old is the donor?";
	cin >> age;
	cout << "What is the house number of the donor?";
	cin >> houseNum;
	cout << "What is the street name of the donor?";
	cin >> streetName;
	cout << "What town does the donor live in?";
	cin >> town;
	cout << "What is the zipcode of the town?";
	cin >> zipcode;
};

void Donor::view(string firstName, string lastName, int age, int houseNum,
		string streetName, string town, string zipcode, 
		float amtDonate){
	cout << "Donor Info" << endl <<
		firstName << " " << lastName << ": age " << age << endl <<
		houseNum << " " << streetName << endl <<
		town << ", NY " << zipcode << endl <<
		"Current Donated Balance: $" << fixed << setprecision(2) << amtDonate<< endl;		
};

void Donor::donate(float &amtDonate){
	string addAmt;
	float addAmtFloat;
	cout << "Please enter an amount to donate: ";
	cin >> addAmt;
	addAmtFloat = stof(addAmt);
	cout << addAmtFloat << endl;
	amtDonate = amtDonate + addAmtFloat;

};

void Donor::total(float amtDonate){
	cout << "Current Donated Balance: $" << fixed << setprecision(2) << amtDonate << endl;
};




