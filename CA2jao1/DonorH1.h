#include <iostream>
#include <stdlib.h>
using namespace std;

class Donor{
	public:
		enum State{NY, PA, RI, NH, VT, MA, CT, ME};

		void manage(string &firstName, string &lastName, int &age, 
				int &houseNum, string &streetName, 
				string &town, string &zipcode);
		void view(string firstName, string lastName, int age, 
				int houseNum, string streetName, string town, 
				string zipcode, float amtDonate);
		void donate(float &amtDonate);
		void total(float amtDonate);
		
		string getFirstName();
		string getLastName();
		string getUserID();
		string getPassword();
		int getAge();
		int getStreetNum();
		string getTown();
		string getState();
		string getZipcode();
		float getAmtDonate();

		void setFirstName(string fn);
		void setLastName(string ln);
		void setUserID(string userid);
		void setPassword(string pw);
		void setAge(int age);
		void setStreetNum(int streetnum);
		void setTown(string Town);
		void setState(string state);
		void setZipcode(string zc);
		void setAmtDonate(float ad);
	private:
		string lastName, firstName, userID, password, streetName,
		       town, zipcode;
		int age, streetNum;
		float amtDonate;	
		State state;	
};
