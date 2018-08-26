#include <iostream>
#include <stdlib.h>
#include "CA1H.h"
#include <string>
#include <algorithm>

using namespace std;

int main(){	
	string lastName = "";
	string firstName = "";
	int age = 0;
	int houseNum = 0;
	string streetName = "";
	string town = "";
	string zipcode = "";
	float  amtDonate = 0;

	std:: string command;
	cout << "What would you like to do?";
	cin >> command;
	std:: transform(command.begin(), command.end(),
			command.begin(), ::toupper);
	
	Donor *donor_ptr = new Donor();
	while (command != "QUIT") {
		if (command == "ADD"){	
			donor_ptr->add(firstName, lastName, age,
					houseNum, streetName, town, 
					zipcode, amtDonate);
		}
		else if (command == "MANAGE"){
			donor_ptr->manage(firstName, lastName, age,
					houseNum, streetName,
				       	town, zipcode);
		}
		else if (command == "VIEW"){
			donor_ptr->view(firstName, lastName, age, houseNum,
					streetName, town, zipcode, amtDonate);
		}		
		else if (command == "DONATE"){
			donor_ptr->donate(amtDonate);
		}
		else if (command == "TOTAL"){
			donor_ptr->total(amtDonate);
		}
		else{
			cout << "Invalid input, please type again. ";
		}
		cout << "What would you like to do?";
		//cout <<'\n' << command << '\n';

		cin >> command;
		std:: transform(command.begin(), command.end(),
			command.begin(), ::toupper);
	}
}

