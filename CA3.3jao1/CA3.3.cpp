#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "FBLUserLLH.h"

using namespace std;

int main(int argc, char **argv){
	bool endProg = false;
	string command;
	string array[5];
	int i = 0;
	FBLUserLL *UserLL = new FBLUserLL();

	cout << "Please enter a command (CREATE <userid> <password> <first> <last>, LOGIN <userid>, USERS, SORTUSERS, QUIT): ";
	getline(cin, command);
	stringstream ssin(command);
	while(ssin.good() && i < 5){
		ssin >> array[i];
		i++;
	}
	while (!endProg){;
		if (array[0] == "CREATE"){
			if (array[1] == "" || array[2] == "" || array[3] == "" || array[4] == ""){
			       cout << "You must completely fill in the necessary information for CREATE" << endl;
			}	
			else{
				string fn = array[3];
				string ln = array[4];
				bool onlyLetters = true;
				for (int i = 0; i < fn.size(); i++){
				//	cout << fn[i] << endl;
					if (!isalpha(fn[i])){
						cout << "First name can only be letters" << endl;
						onlyLetters = false;
						break;
					}
				}
				if (onlyLetters){
					for (i = 0; i < ln.size(); i++){
						if (!isalpha(ln[i])){
							cout << "Last name can only be letters" << endl;
							onlyLetters = false;
							break;
						}
					}
				}
				if (onlyLetters){
					UserLL -> create(array[1], array[2], array[3], array[4]);
				}
			}
		//	cout << "HM" << endl;
		}
		else if (array[0] == "LOGIN"){
			UserLL -> login(array[1], array[2]);
		}
		else if (array[0] == "USERS"){
			UserLL -> users();
		}
		else if (array[0] == "SORTUSERS"){
			UserLL -> sortUsers();
		}
		else if (array[0] == "QUIT"){
			delete UserLL;
			break;
		}
		else{
			cout << "Sorry, that was an invalid command" << endl;
		}
		cout << "Please enter a command (CREATE <userid> <password> <first> <last>, LOGIN <userid>, USERS, SORTUSERS, QUIT): ";
		getline(cin, command);
		stringstream ssin(command);
		i = 0;
		
		array[0] = "";
		array[1] = "";
		array[2] = "";
		array[3] = "";
		array[4] = "";
		while(ssin.good() && i < 5){
			ssin >> array[i];
			i++;
		}	

	}
}


