#include <iostream>
#include <stdlib.h>
#include "DonorH.h"
#include <iomanip> 
#include <string>
#include <math.h>
#include <limits>
#include <sstream>
#include <locale>
#include <stdio.h>

using namespace std;
string firstName;

void Donor::add2(string &firstName, string &lastName, int &age, 
		int &houseNum, string &streetName, string &town, 
		string &zipcode, float &amtDonate){

	string str;
	float floatNum;

	cout << "What is the donor's first name?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the first name again: ";
		cin >> str;	
	}
	firstName = str;

	cout << "What is the donor's last name?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the last name: ";
		cin >> str;
	}
	lastName = str;
	
	cout << "How old is the donor?";
	cin >> str;
	while (!isWholeNum(str)){
		cout << "Invalid input. Please write the age: ";
		cin >> str;
	}
	age = std::stoi(str);

	cout << "What is the house number of the donor?";
	cin >> str;	
	while (!isWholeNum(str)){
		cout << "Invalid input. Please write the house number: ";
		cin >> str;
	}
	houseNum = std::stoi(str);

	cout << "What is the street name of the donor?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the street name: ";
		cin >> str;
	}
	streetName = str;

	cout << "What town does the donor live in?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the town: ";
		cin >> str;
	}
	town = str;

	cout << "What is the zipcode of the town?";
	cin >> str;
	while (!isWholeNum(str) || str.size() != 5){
		cout << "Invalid input. Please write the zipcode: ";
		cin >> str;
	}
	zipcode = std::stoi(str);

	cout << "How much would the donor like to donate?";
	cin >> floatNum;
	while (cin.fail() || floatNum < 0){
		cout << "Invalid input. Please enter the amount the donor would like to donate: ";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> floatNum;
	}
	amtDonate = floatNum;
	
};

void Donor::manage(string &firstName, string &lastName, int &age, 
		int &houseNum, string &streetName, string &town, 
		string &zipcode){
	
	string str;
	float floatNum;

	cout << "What is the donor's first name?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the first name again: ";
		cin >> str;	
	}
	firstName = str;

	cout << "What is the donor's last name?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the last name: ";
		cin >> str;
	}
	lastName = str;
	
	cout << "How old is the donor?";
	cin >> str;
	while (!isWholeNum(str)){
		cout << "Invalid input. Please write the age: ";
		cin >> str;
	}
	age = std::stoi(str);

	cout << "What is the house number of the donor?";
	cin >> str;	
	while (!isWholeNum(str)){
		cout << "Invalid input. Please write the house number: ";
		cin >> str;
	}
	houseNum = std::stoi(str);

	cout << "What is the street name of the donor?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the street name: ";
		cin >> str;
	}
	streetName = str;

	cout << "What town does the donor live in?";
	cin >> str;
	while (!isLetter(str)){
		cout << "Invalid input. Please write the town: ";
		cin >> str;
	}
	town = str;

	cout << "What is the zipcode of the town?";
	cin >> str;
	while (!isWholeNum(str) || str.size() != 5){
		cout << "Invalid input. Please write the zipcode: ";
		cin >> str;
	}
	zipcode = std::stoi(str);

	/*cout << "How much would the donor like to donate?";
	cin >> floatNum;
	while (cin.fail() || floatNum < 0){
		cout << "Invalid input. Please enter the amount the donor would like to donate: ";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> floatNum;
	}
	amtDonate = floatNum;*/
}

void Donor::view(string firstName, string lastName, int age, int houseNum,
		string streetName, string town, string zipcode, 
		float amtDonate){
	cout << "Donor Info" << endl <<
		firstName << " " << lastName << ": age " << age << endl <<
		houseNum << " " << streetName << endl <<
		town << ", NY " << zipcode << endl <<
		"Current Amount Donated: $" << fixed << setprecision(2) << amtDonate << endl;
};

void Donor::donate(float &amtDonate){
	int addAmt;
	float floatNum;

	cout << "Please enter an amount to donate: ";
	cin >> addAmt;
	while (cin.fail() || floatNum < 0){
		cout << "Invalid input. Please enter the amount the donor would like to donate: ";
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> addAmt;
	}
	amtDonate = amtDonate + addAmt;
	amtDonate = roundf(amtDonate * 100)/100;
};

void Donor::total(float amtDonate){
	cout << "Current Donated Balance: $" << fixed << setprecision(2) << amtDonate << endl;
};

bool Donor::isLetter(const string str){
	bool retVal = true;
	for (int i = 0; i < str.size(); i++){
		//cout << str[i];
		if (!isalpha(str[i]) || isspace(str[i])){
			retVal = false;
		break;
		}
	}
	return retVal;
}

bool Donor::isWholeNum(const string str){
	bool isInt = false;
	std:: locale loc;
	for (int i = 0; i < str.size(); i++){
		if (!isdigit(str[i], loc)){
			isInt = false;
			break;
		}
		if (i == str.size()-1){
			isInt = true;
		}
	}
	return isInt;
}

void setLastName(string ln);
void setFirstName(string fn);
void setUserID(string userid);
void setPassword(string pw);
void setAge(int Age);
void setStreetNum(int streetnum);
void setTown(string Town);
void setZipcode(string zipcode);
void setAmtDonate(float ad);

void setFirstName(string fn){
	firstName = fn;
}

string getFirstName(){
	return firstName;
}



