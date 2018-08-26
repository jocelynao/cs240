#include <iostream>
#include <stdlib.h>
#include "DonorDatabaseH.h"
//#include "DonorH.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <cctype>

using namespace std;

int donorArrayPlace = 0;
int sizeArray;
Donor *donorArray;
	
DonorDatabase::DonorDatabase(int arraySize){
	donorArray = new Donor[arraySize];
	sizeArray = arraySize;
	//cout << donorArray[0];
}

void DonorDatabase::secondMenu(Donor &donor){
	//cout << donor.getFirstName() << endl;
//	cout << donor.getUserID() << endl;
	string command;
	//cout << "WHY" << endl;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "You have logged in. What would you like to do? Please enter a command [Manage, Password, View, Donate, Total, Logout]: ";
	//cin >> command;
	getline(cin, command);
	while (command != "Logout"){
		if (command == "Manage"){
			donor.manage();
		}
		else if (command == "Password"){
			donor.changePW();
		}
		else if( command == "Donate"){
			donor.donate();
		}
		else if (command == "View"){
			donor.view();
		}
		else if (command == "Total"){
			donor.total();
		}
		else{
			cout << "Please type in a valid command." << endl;
		}
		cout << "What would you like to do? Please enter a command [Manage, Password, View, Donate, Total, Logout]: ";
		getline(cin, command);
	}
}

void DonorDatabase::login(){
	string user;
	string password;
	int userInfo;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Username: ";
	getline(cin, user);
	bool validUser = false;
	while (!validUser){
	//	cout << "JJ"<< endl;
		if (!user.empty()){
		//	cout << ">" << endl;
		//	cout << donorArrayPlace << endl;
			for (userInfo = 0; userInfo <= donorArrayPlace; userInfo++){
		//		cout << "WHY" << endl;
			//	cout << donorArray[userInfo].getUserID() << endl;
				if (donorArray[userInfo].getUserID() == user){				
				//	cout << "H!" << endl;
					validUser = true;
					break;
				}	
			}
			if (!validUser){
				cout << "Username not recognized. Please try again: ";
				getline(cin, user);
			}
		}
		else{
			cout << "Username: ";
			getline(cin, user);
		}
	}

	cout << "Password: ";
	getline(cin, password);
	bool validPW = false;
	while (!validPW){
		if (!password.empty()){
			if (donorArray[userInfo].getPassword() != password){
				cout << "Wrong password. Please try again: ";
				getline(cin, password);
			}
			else{
				validPW = true;
			}
		}
		else{
			cout << "Password: ";
			getline(cin, password);
		}
	}
	secondMenu(donorArray[userInfo]);
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void DonorDatabase::add(){
	//cout << "$" << donorArray[donorArrayPlace].getUserID() << "$" << endl;
	if (donorArrayPlace != (sizeArray)){
		string str;
	//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//cout << donorArray[0];
		cout << "What is the donor's first name? ";
		getline(cin, str);
		while (!isLetter(str) || str.empty()){
			cout << "Invalid input. Please write the first name again: ";
			getline(cin, str);	
		}
		donorArray[donorArrayPlace].setFirstName(str);
		//cout << donorArray[donorArrayPlace].getFirstName();
		
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "What is the donor's last name? ";
		getline(cin, str);
		while (!isLetter(str) || str.empty()){
			cout << "Invalid input. Please write the last name again: ";
			getline(cin, str);
		}
		donorArray[donorArrayPlace].setLastName(str);

		cout << "What do you want your username to be? It can contain letters or digits but must be between 5 and 10 characters:  ";
		getline(cin, str);
		bool validNewUser = false;
		while(!validNewUser){
			if (!str.empty()){
				for (int i = 0; i < sizeArray; i++){
					if (donorArray[i].getUserID() == str){
						cout << "That username is taken. Please enter another one: ";
						getline(cin, str);
					}
					else{
						if (str.size() < 5 || str.size() > 10){
							cout << "Username must be between 5 and 10 characters. It can have letters and digits. Please enter another one: ";
							getline(cin, str);
						}
						else{
							validNewUser = true;
							for (int i = 0; i < str.size(); i++){
								if (!isalpha(str[i]) && !isdigit(str[i])){
									cout << "Username can only be letters and digits and they must be between 5 and 10 characters. Please enter another one: ";
									getline(cin, str);
									validNewUser = false;
								}
							}	
						}	
					}
				}
			}
			else{
				cout << "Invalid username. Username can only be letters and digits and they must be between 5 and 10 characters. Please enter another one: ";
				getline(cin, str);
			}
		}
		donorArray[donorArrayPlace].setUserID(str);
	
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		cout << "What do you want the password to be? It must be at least 6 characters and have at least one special character and at least one digit: ";
		getline(cin, str);
		bool validPW = false;
		int numDigits = 0;
		int numSpecialChar = 0;
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
					validPW = true;
				}
			}
		}
		donorArray[donorArrayPlace].setPassword(str);
		//cout << donorArray[donorArrayPlace].getPassword();

		cout << "What is the donor's age: ";
		getline(cin, str);
		bool validNum = false;
		while (!validNum){
			if (!isWholeNum(str)){
				cout << "Age must be a number. Please enter in a valid age: ";
				getline(cin, str);
			}
			else{
				if (stoi(str) < 18){
					cout << "You must be at least 18 to donate. Please reenter your age or suspend the program: ";
		       			getline(cin, str);
				}
				else{
					validNum = true;
				}	
			}
		}
		donorArray[donorArrayPlace].setAge(stoi(str));

		cout << "What is the donor's street number? ";
		getline(cin, str);
		bool validStreetNum = false;
		while (!validStreetNum){
			if (!isWholeNum(str)){
				cout << "Street number must be a number. Please enter in a valid street number ";
				getline(cin, str);
			}
			else{
				validStreetNum = true;
			}
		}
		donorArray[donorArrayPlace].setStreetNum(stoi(str));

		cout << "What is the donor's street name? ";
		getline(cin, str);
		bool validStreet = false;
		bool hasLetter = false;
		while (!validStreet){
			if (!str.empty()){
				int validChar = 0;
				for (int i = 0; i < str.size(); i++){
					if (isalpha(str[i]) || str[i] == ' ' || str[i] == '\t')
						validChar = validChar + 1;
						if (isalpha(str[i])){
							hasLetter = true;
						}
						//cout << validChar;
					}
				if (validChar != str.size()){
					cout << "Street names can only have letters and spaces. Please enter again: ";
					//cout << "WHY";
					getline(cin, str);
					//cout << "HEIR";
				}
				if (!hasLetter){
					cout << "Please enter a valid street name: ";
					getline(cin, str);
				}

				else{
					validStreet = true;
				}
			}
			else{
				cout << "Please enter the donor's street name: ";
				getline(cin, str);
			}
		}
		donorArray[donorArrayPlace].setStreetName(str);

		cout << "What is the donor's town? ";
		getline(cin, str);
		bool validTown = false;
		hasLetter = false;
		while (!validTown){
			if (!str.empty()){
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
					cout << "Towns can only have letters and spaces. Please enter again: ";
					//cout << "WHY";
					getline(cin, str);
					//cout << "HEIR";
				}
				if (!hasLetter){
					cout << "Please enter a valid town name: ";
					getline(cin, str);
				}
				else{
					validTown = true;
				}
			}
			else{
				cout << "Please enter the donor's town: ";
				getline(cin, str);
			}
		}
		donorArray[donorArrayPlace].setTown(str);

		cout << "What state does the donor live in? Please pick NY, PA, RI, NH, VT, MA, CT, or ME ";
		getline(cin, str);
		bool validState = false;
		while (!validState){
			if (str == "NY" || str == "PA" || str == "RI" ||
					str == "NH" || str == "VT" || 
					str == "MA" || str == "CT" ||
					str == "ME"){
				donorArray[donorArrayPlace].setState(str);
				//cout << donorArray[donorArrayPlace].getState();
				validState = true;
			}
			else{
				cout << "Invalid input. Please enter [NY, PA, RI, NH, VT, MA, CT, or ME] ";
				getline(cin, str);
			}
		}
		donorArray[donorArrayPlace].setState(str);

		cout << "What is the donor's zipcode? ";
		getline(cin, str);
		bool validZip = false;
		while (str.size() != 5 || !isWholeNum(str)){
			cout << "Zipcode should only have numbers and be five digits long.Please enter again: ";
			getline(cin, str);
		}
		donorArray[donorArrayPlace].setZipcode(str);
		donorArrayPlace = donorArrayPlace + 1;
	}
	else{
		cout << "Sorry, there is no more space in this database for more users" << endl;
	}
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


}

void DonorDatabase::save(){
	string fileName;
	string answer;
//	getline(cin, str);
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	bool fileDone = false;
	cout << "What would you like to name the file?";
//	cout << "$" << endl;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	getline(cin, fileName);
//	cout << fileName.size() << endl;
	while (!fileDone){
		if (!fileName.empty()){
			if (fileExists(fileName)){
				cout << "That file already exists. Would you like to overwrite it? Enter 'Y' or press any other key to go back to the previous prompt: ";
				getline(cin, answer);
				if (answer == "Y"){
					write(fileName);
					fileDone = true;
					cout << "File has been saved.\n";
				}	
				else {
					cout << "What would you like to name the file? ";
					getline(cin, fileName);
				}
			}
			else {
				int numSpaces = 0;
				for (int i = 0; i < fileName.size(); i++){
					if (fileName[i] == ' ' || fileName[i] == '\t'){
						numSpaces = numSpaces + 1;
					}
				}
				if (numSpaces != fileName.size()){
					write(fileName);
					cout << "File has been saved.\n";
					fileDone = true;
				}
				else{
					cout << "File name can't just be spaces. Please enter again: ";
					getline(cin, fileName);
				}
			}
		}
		else {
			cout << "What would you like to name the file? ";
			getline(cin, fileName);
		}
	}
}

void DonorDatabase::load(string fileName){
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (fileName.empty()){
		cout << "Enter the file you would like to load: ";
		getline(cin, fileName);
	}

	bool fileDone = false;
	while (!fileDone){
		if (!fileExists(fileName)){
			cout << "That file does not exist. Please type in the filename again: ";
			getline(cin, fileName);
		}
		else{
			read(fileName);
			fileDone = true;
		}
	}

}

void DonorDatabase::report(){
	float amtTotal = 0;
	for (int i = 0; i < donorArrayPlace; i++){
		amtTotal = amtTotal + donorArray[i].getAmtDonate();
	}

	cout << "Total amount of users in database: " << donorArrayPlace << endl;
	cout << "Total amount of money donated: " << amtTotal << endl;
}

void DonorDatabase::quit(){
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	string str;
	cout << "Would you like to save first? Type 'Y' or 'N': ";
	getline(cin, str);
	bool valid = false;
	while (!valid){
		if (!str.empty()){
		//	cout << "HOW" << endl;
			if (str == "Y"){
				save();
				valid = true;
			}
			else if (str == "N"){
				valid = true;
			//	cout << "WHY" << endl;
			}
			else {
				cout << "Please type 'Y' or 'N': ";
				getline(cin, str);
			//	cout << "WHAT" << endl;
			}
		}
		else {
				cout << "Please type 'Y' or 'N': ";
				getline(cin, str);
		}
	}
}

bool DonorDatabase::isLetter(const string str){
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

bool DonorDatabase::isWholeNum(const string str){
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

/*bool onlySpaces(const string &str){
	char *token = strtok(const_cast<char*>(str.c_str()), "");
	while (token != NULL){
		if (*token != ' ')
	}
}
*/
inline bool DonorDatabase::fileExists(const string &name){
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0);
}

void DonorDatabase::write(string fileName){
	ofstream file;
	file.open(fileName);
	
	file << donorArrayPlace;
	file << endl;
	file << endl;

	for (int i = 0; i < donorArrayPlace; i++){
		file << donorArray[i].getFirstName() << endl;
		file << donorArray[i].getLastName() << endl;
		file << donorArray[i].getUserID() << endl;
		file << donorArray[i].getPassword() << endl;
		file << donorArray[i].getAge() << endl;
		file << donorArray[i].getStreetNum() << endl;
		file << donorArray[i].getStreetName() << endl;
		file << donorArray[i].getTown() << endl;
		file << donorArray[i].getState() << endl;
		file << donorArray[i].getZipcode() << endl;
		file << donorArray[i].getAmtDonate() << endl; 
		file << endl;
	}
	file.close();
}

void DonorDatabase::read(string fileName){
	ifstream file;
	file.open(fileName);
	int num;
	string str;

//	cout << "here" << endl;

	file >> num;
	if (num > sizeArray){
		cout << "Sorry but the database can only fit " << sizeArray << " donors and the file has " << num << " donor(s). The database is currently empty with " << sizeArray << " spac spaces available"  << endl;
	}
	else {

		donorArrayPlace = num;
	//	cout << donorArrayPlace << endl;
	//	cout << "HEREER";
	//
	//	int arrayPlace = 0;
		for (int i = 0; i < donorArrayPlace; i++){
			file >> str;
		
	//		cout << str << " 0" <<  endl;
			donorArray[i].setFirstName(str);
			file >> str;
	//		cout << str << " 1" << endl;
			donorArray[i].setLastName(str);
			file >> str;
	//		cout << str << " 2" << endl;
			donorArray[i].setUserID(str);
			file >> str;
	//		cout << str << " 3" << endl;
			donorArray[i].setPassword(str);
			file >> str;
	//		cout << str << " 4" << endl;
			donorArray[i].setAge(stoi(str));
			file >> str;
	//		cout << str << " 5" << endl;
			donorArray[i].setStreetNum(stoi(str));
			file >> str;
	//		cout << str << " 6" << endl;
			donorArray[i].setStreetName(str);
			file >> str;
	//		cout << str << " 6.5" << endl;
			donorArray[i].setTown(str);
			file >> str;
	//		cout << str << " 7" << endl;
			donorArray[i].setState(str);
			file >> str;
	//		cout << str << " 8" << endl;
			donorArray[i].setZipcode(str);
			file >> str;
	//		cout << str << " 9" << endl;
			donorArray[i].setAmtDonate(stof(str));

	//		cout << "DonorArray: " << i << endl;
	//		cout << endl;
		}
		cout << "Database has been updated with the file contents" << endl;			
	}
	file.close();
}

DonorDatabase::~DonorDatabase(){
	delete []donorArray;
}
