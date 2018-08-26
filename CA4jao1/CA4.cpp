#include <iostream>
#include <stdlib.h>
#include "DishH.h"

using namespace std;

int main(){
	Dish *dish = new Dish;
	string command;
	string word;
	string word2;

	while (true){
		cout << "What would you like to do? Please enter a command (INSERT, FIND, CAPITALIZE, ALLCAPS, TRUNCATE, GETSHORTEST, GETFIRST, PRINT, QUIT): ";
		getline(cin, command);
		if (command == "INSERT"){
			cout << "What string would you like to insert?: ";
			getline(cin, word);
			int index = dish -> insert(word);
			cout << "Index of inserted string is " << index << endl;
		}
		else if (command == "FIND"){
			cout << "What string would you like to find?: ";
			getline(cin, word);
			int index = dish -> find(word);
			if (index == -1){
				cout << "This string was not added" << endl;
			}
			else{
				cout << "Index of string is " << index << endl;
			}
		}
		else if (command == "CAPITALIZE"){
			cout << "Pick an index to capitalize. The size of the Dish is " << dish -> getCount() << ": ";
			getline(cin, word);
			bool isNum = true;
			for (int i = 0; i < word.length() ; i++){
				if (!isdigit(word[i])){
					isNum = false;
					break;
				}
			}
			if (isNum){
				bool done = dish -> capitalize(stoi(word));
				if (done == false){
					cout << "Chosen index is outside the range. Please try again." << endl;
				}
			}
			else{
				cout << "Not a valid input. Please try again. ";
			}
		}
		else if (command == "ALLCAPS"){
			cout << "Pick an index to make all caps. The size of the Dish is " << dish -> getCount() << ": ";
			getline(cin, word);
			bool isNum = true;

			for (int i = 0; i < word.length(); i++){
				if (!isdigit(word[i])){
					isNum = false;
					break;
				}
			}
			if (isNum){
			//	cout << "E" << endl;
				bool done = dish -> allcaps(stoi(word));
				if (done == false){
					cout << "Chosen index is outside the range. Please try again." << endl;
				}
			}
			else{
				cout << "Not a valid input. Please try again. ";
			}
		}
		else if (command == "TRUNCATE"){
			cout << "Pick an index to truncate. The size of the Dish is " << dish -> getCount() << ": ";
			getline(cin, word);
			bool isNum = true;
			for (int i = 0; i < word.length(); i++){
				if (!isdigit(word[i])){
					isNum = false;
					break;
				}
			}
			if (isNum){
			//	cout << stoi(word) << endl;
			//	cout << dish -> getCount() << endl;
			//	cout << dish -> getCount() << endl;
				if (stoi(word) <= dish -> getCount() && stoi(word) >= 0){
					cout << "How many characters do you want to keep? The word is '" << dish -> getDishVec()[stoi(word)].getString() << "': ";
					getline(cin, word2);
					for (int i = 0; i < word2.length(); i++){
						if (!isdigit(word2[i])){
							isNum = false;
							break;
						}
					}
					if (isNum){
				//	cout << "E" << endl;
						bool done = dish -> truncate(stoi(word), stoi(word2));
						if (done == false){
							cout << "Chosen number is more than the length of the word. Please try again." << endl;
						}
					}
					else{
						cout << "Not a valid input. Please try again. ";
					}
				}
				else{
					cout << "Index is out of range. Please try again. ";
				}
			}
			else{
				cout << "Not a valid input. Please try again. ";
			}

		}
		else if (command == "GETSHORTEST"){
			if (dish -> getCount() == 0){
				cout << "There are no strings in the dish right now" << endl;
			}
			else{
				string shortest = dish -> getshortest();
				cout << "Shortest string is " << shortest << endl;
			}
		}
		else if (command == "GETFIRST"){
			if (dish -> getCount() == 0){
				cout << "There are no strings in the dish right now" << endl;
			}
			else{
				string first = dish -> getfirst();
				cout << "First string is " << first << endl;
			}
		}
		else if (command == "PRINT"){
			dish -> print();
		}
		else if (command == "QUIT"){
			delete dish;
			break;
		}
		else{
			cout << "Sorry, that is not a valid command. Please enter again. ";
		}
	}
}

