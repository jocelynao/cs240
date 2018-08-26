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
/*string firstName = "Jocelyn";
string lastName = "Ao";
string userID = "jao1";
string password = "jao";
int age = 21;
int streetNum = 44;
string town = "Monroe";
string zipcode = "10950";
float amtDonate = 4325.32;
*/
	
//enum State{NY, PA, RI, NH, VT, MA, CT, ME};
//State state;

void Donor::manage(){
	string str;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Type in the first name you want to change to or press enter to skip: ";
	getline(cin, str);
	bool done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else {
			if (isLetter(str)){
				done = true;
				firstName = str;
			}
			else{
				cout << "Names can only contain letters. Please write the first name again: ";
				getline(cin, str);	
			}
		}
	}

	cout << "Type in the last name you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else {
			if (isLetter(str)){
				done = true;
				lastName = str;
			}
			else{
				cout << "Names can only contain letters. Please write the last name again or press enter to skip: ";
				getline(cin, str);	
			}
		}
	}

	cout << "Type in the age you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			if (!isWholeNum(str)){
				cout << "Age must be a number. Please enter in a valid age: ";
				getline(cin, str);
			}
			else{
				if (stoi(str) < 18){
					cout << "You must be at least 18 to donate. Please reenter your age or press enter to skip: ";
					getline(cin, str);
				}
				else{
					age = stoi(str);
					done = true;
				}
			}
		}
	}
	
	cout << "Type in the street number you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			if (!isWholeNum(str)){
				cout << "Street number must be a number. Please enter in a valid street number or press enter to skip: ";
				getline(cin, str);
			}
			else{
				streetNum = stoi(str);
				done = true;
			}
		}
	}

	cout << "Type in the street name you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	bool hasLetter = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			int validChar = 0;
			for (int i = 0; i < str.size(); i++){
				if (isalpha(str[i]) || str[i] == ' ' || str[i] == '\t')
					validChar = validChar + 1;
					//cout << validChar;
					if (isalpha(str[i])){
						hasLetter = true;
					}
				}
			if (validChar != str.size()){
				cout << "Street names can only have letters and spaces. Please type it in again or press enter to skip: ";
				//cout << "WHY";
				getline(cin, str);
				//cout << "HEIR";
			}
			if (!hasLetter){
				cout << "Please enter a valid street name: ";
				getline(cin, str);
			}
			else{
				streetName = str;
				done = true;
			}
		}
	}

	cout << "Type in the town you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	hasLetter = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			int validChar = 0;
			for (int i = 0; i < str.size(); i++){
				if (isalpha(str[i]) || str[i] == ' ' || str[i] == '\t')
					validChar = validChar + 1;
					if (isalpha(str[i])){
						hasLetter = true;
					}
			}
			if (validChar != str.size()){
				cout << "Towns can only have letters and spaces. Please type it in again or press enter to skip : ";
				//cout << "WHY";
				getline(cin, str);
				//cout << "HEIR";
			}
			if (!hasLetter){
				cout << "Please enter a valid town name: ";
				getline(cin, str);
			}
			else{
				town = str;
				done = true;
			}
		}
	}

	cout << "Type in the state you want to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			if (str == "NY" || str == "PA" || str == "RI" ||
					str == "NH" || str == "VT" || 
					str == "MA" || str == "CT" ||
					str == "ME"){
				setState(str);
				done = true;
			}
			else {
				cout << "Invalid input. Please enter [NY, PA, RI, NH, VT, MA, CT, or ME] or press enter to quit: ";
				getline(cin, str);
			}
		}
	}

	cout << "Type in the zipcode you would like to change to or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{
			if (str.size() != 5 || !isWholeNum(str)){
				cout << "Zipcode should only have numbers and be five digits long. Please type it in again or press enter to skip: ";
				getline(cin, str);
			}
			else{
				zipcode = str;
				done = true;
			}
		}
	}

	cout << "Type in the amount you wish to change to donate or press enter to skip: ";
	getline(cin, str);
	done = false;
	while (!done){
		if (str.empty()){
			done = true;
		}
		else{	
			int i = 0;
			bool decFound = false;
			for (i = 0; i < str.size(); i++){
				if (!isdigit(str[i])){
					if (!decFound && str[i] == '.'){
						decFound = true;
					}
					else{
						break;
					}
				}
			}
			if (i != (str.size())){
				cout << "Invalid input. Please type again or press enter to skip. You cannot donate more than $5000: ";
				getline(cin, str);
			}
			else{
				if (stof(str) < 0 || stof(str) > 5000){
					cout << "Invalid input. Please type again or press enter to skip. You cannot donate more than $5000: ";
					getline(cin, str);
				}
				else{
					amtDonate = stof(str);
					done = true;
				}
			}
		}
	}

	cout << "Changes made. ";
}

void Donor::changePW(){
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string str;
	bool correctPW = false;

	cout << "Password: ";
	getline(cin, str);
	while (!correctPW){
		if (str != password){
			cout << "Password incorrect. Please try again: ";
			getline(cin, str);
		}
		else{
			correctPW = true;
		}
	}

	cout << "Please enter the new password. It must be at least 6 characters and have at least one special character and at least one digit: ";
	getline(cin, str);
	bool validPW = false;
	int numDigits = 0;
	int numSpecialChar = 0;
	string newPW;
	while (!validPW){
		if (str.size() < 6){
			cout << "Password must be at least 6 characters and have at least one special character and at least one digit: ";
			getline(cin, str);
		}
		else {
			for (int i = 0; i < str.size(); i++){
				if (isdigit(str[i])){
					numDigits = numDigits + 1;
				}
				if (!isdigit(str[i]) && !isalpha(str[i])){
					numSpecialChar = numSpecialChar + 1;
				}
			}
			if (numDigits < 1 || numSpecialChar < 1){
				cout << "Password must have at least one special character and one number: ";
				getline(cin, str);
				numDigits = 0;
				numSpecialChar = 0;
			}	
			else {
				newPW = str;
				cout << "Please reenter the new password: ";
				getline(cin, str);
				if (str != newPW){
					cout << "Passwords do not match. Please type it twice again. Password must be at least 6 characters and have at least one special character and at least one digit: ";
					getline(cin, str);
				}
				else{
					password = str;
					validPW = true;
				}
			}
		}
	}
	cout << "Change made. ";
}

void Donor::view(){
	cout << "Donor Info" << endl <<
		firstName << " " << lastName << ": " << "age " << age << endl <<
		streetNum << " " << streetName << endl << 
		town << ", " << getState() << " " << zipcode << endl <<
		"Current Amount Donated: $" << setprecision(2) << fixed << amtDonate << endl;
}

void Donor::donate(){
	string str;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Type in the amount you wish to donate. The amount can't be more than $5000: ";
	getline(cin, str);
	bool validNum = false;
	while (!validNum){
		if (!str.empty()){
			int i = 0;
			bool decFound = false;
			for (i = 0; i < str.size(); i++){
				if (!isdigit(str[i])){
					if (!decFound && str[i] == '.'){
						decFound = true;
					}
					else{
						break;
					}
				}
			}
			if (i != str.size()){
				cout << "Invalid amount. Please type it again. The amount can't be more than $5000: ";
				getline(cin, str);
			}
			else{
				if (stof(str) > 5000){
					cout << "Invalid amount. Please type it again. The amount can't be more than $5000: ";
					getline(cin, str);
				}
				else{
					validNum = true;
				}
			}
		}
		else {
			cout << "Please type in the amount you wish to donate: ";
			getline(cin, str);
		}
	}
	amtDonate = stof(str) + amtDonate;
}

void Donor::total(){
	cout << lastName << " $" << setprecision(2) << fixed << amtDonate << endl;
}

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


string Donor::getFirstName(){
	return firstName;
}
string Donor::getLastName(){
	return lastName;
}
string Donor::getUserID(){
	return userID;
}
string Donor::getPassword(){
	return password;
}	
int Donor::getAge(){
	return age;
}
int Donor::getStreetNum(){
	return streetNum;
}

string Donor::getStreetName(){
	return streetName;
}

string Donor::getTown(){
	return town;
}
string Donor::getState(){
	string retStr;
	switch (state){
		case NY:
			retStr = "NY";
			break;
		case PA:
			retStr = "PA";
			break;
		case RI:
			retStr = "RI";
			break;
		case NH:
			retStr = "NH";
			break;
		case VT:
			retStr = "VT";
			break;
		case MA:
			retStr = "MA";
			break;
		case CT:
			retStr = "CT";
			break;
		case ME:
			retStr = "ME";
			break;
	}
	return retStr;
}
string Donor::getZipcode(){
	return zipcode;
}
float Donor::getAmtDonate(){
	return amtDonate;
}

void Donor::setFirstName(string fn){
	firstName = fn;
}
void Donor::setLastName(string ln){
	lastName = ln;
}
void Donor::setUserID(string userid){
	userID = userid;
}
void Donor::setPassword(string pw){
	password = pw;
}
void Donor::setAge(int Age){
	age = Age;
}
void Donor::setStreetNum(int streetnum){
	streetNum = streetnum;
}
void Donor::setStreetName(string streetname){
	streetName = streetname;
}
void Donor::setTown(string Town){
	town = Town;
}
void Donor::setState(string s){
	if (s == "NY"){
		state = NY;
	}
	else if (s == "PA"){
		state = PA;
	}
	else if (s == "RI"){
		state = RI;
	}
	else if (s == "NH"){
		state = NH;
	}
	else if (s == "VT"){
		state = VT;
	}
	else if (s == "MA"){
		state = MA;
	}
	else if (s == "CT"){
		state = CT;
	}
	else{
		state = ME;
	}
}
void Donor::setZipcode(string zc){
	zipcode = zc;
}
void Donor::setAmtDonate(float ad){
	amtDonate = ad;
}




