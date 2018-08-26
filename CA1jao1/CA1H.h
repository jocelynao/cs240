#include <iostream>
#include <stdlib.h>
using namespace std;

class Donor{
	public:
		void add(string &firstName, string & lastName, int & age, 
				int &houseNum, string &streetName,
			       	string &town, string &zipcode,
				float &amtDonate);
		void manage(string &firstName, string &lastName, int &age, 
				int &houseNum, string &streetName, 
				string &town, string &zipcode);
		void view(string firstName, string lastName, int age, 
				int houseNum, string streetName, string town, 
				string zipcode, float amtDonate);
		void donate(float &amtDonate);
		void total(float amtDonate);

		
};
