#include <iostream>
#include <stdlib.h>
#include "DonorDatabaseH.h"
#include "DonorH.h"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char **argv){

	int arraySize;
	string progName(argv[0]);
	
	if (argc == 1 || argc > 3){
		cout << "You ran the program with incomplete arguments. Please run it like this: ./Donate <max donors> <filename>" << endl;
		cout << "The filename is optional" << endl;
	}
	else{
	//	cout << "HI" << endl;
		istringstream buf(argv[1]);
		string argument;
		buf >> argument;

		bool validArg = false;
		bool passOne = true;
		int i;
		for (i = 0; i < argument.size(); i++){
			if (!isdigit(argument[i])){
				cout << "The max donor must be a letter and can't be decimals. Please run the program like this: ./Donate <max donors> <filename> " << endl;
				passOne = false;
				break;
			}
		}
		if (passOne){
		//	cout << "E" << endl;
			arraySize = stoi(argument);
			if (arraySize < 0){
				cout << "The max donor can't be negative. Please run the program like this: ./Donate <max donors> <filename> "; 
			}
			else {
			//	cout << "ERRR" << endl;
				validArg = true;
			}
		}
		if (validArg){
			DonorDatabase *dbPointer = new DonorDatabase(arraySize);
			if (argc == 3){
				string fileName;
				istringstream buf(argv[2]);
				buf >> fileName;
				dbPointer -> load(fileName);
			}
				
			bool endProg = false;
			string command;
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "What would you like to do? Please enter a command: [\"Login\", \"Add\", \"Save\", \"Load\", \"Report\", \"Quit\"]: ";
			getline(cin, command);

			while (!endProg){
				if (!command.empty()){
					if (command == "Login"){
						dbPointer -> login();
					}
					else if (command == "Add"){
						dbPointer -> add();
					}
					else if (command == "Save"){
						dbPointer -> save();
					}
					else if (command == "Load"){
						dbPointer -> load();
					}
					else if (command == "Report"){
						dbPointer -> report();
					}
					else if (command == "Quit"){
						dbPointer -> quit();
						dbPointer -> ~DonorDatabase();
						break;
					}
					else {
						cout << "Not a valid command. Please re=enter. " << endl;
					}
				}
				else{
					cout << "What would you like to do? Please enter a command: [\"Login\", \"Add\", \"Save\", \"Load\", \"Report\", \"Quit\"]: ";
					getline(cin, command);
				}
				cout << "What would you like to do? Please enter a command: [\"Login\", \"Add\", \"Save\", \"Load\", \"Report\", \"Quit\"]: ";
				getline(cin, command);
			}
		}
	}
}

