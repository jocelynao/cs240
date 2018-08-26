#include <iostream>
#include <stdlib.h>
#ifndef DonorH
#define DonorH

using namespace std;

class Donor{
	public:
		enum State{NY, PA, RI, NH, VT, MA, CT, ME};

		void manage();
		void changePW();
		void view();
		void donate();
		void total();
		
		string getFirstName();
		string getLastName();
		string getUserID();
		string getPassword();
		int getAge();
		int getStreetNum();
		string getStreetName();
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
		void setStreetName(string streetName);
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

		bool isLetter(string str);
		bool isWholeNum(const string str);
};

#endif
