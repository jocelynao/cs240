#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include "DonorH.h"

using namespace std;

class DonorDatabase{
	public:
		//donorArray(int arraySize);
		DonorDatabase(int arraySize);
		
		void login();
		void add();
		void save();
		void load(string fileName = "");
		void report();
		void quit();
		~DonorDatabase();
		

	/*	void setLastName(string ln);
		void setFirstName(string fn);
		void setUserID(string userid);
		void setPassword(string pw);
		void setAge(int Age);
		void setStreetNum(int streetnum);
		void setTown(string Town);
		void setZipcode(string zipcode);
		void setAmtDonate(float ad);

		string getLastName();
		string getFirstName();
		string getUserID();
		string getPassword();
		int getAge();
		int getStreetNum();
		string getTown();
		string getZipCode();
		float getAmtDonate();
	`*/
	private:
		void secondMenu(Donor &donor);
		bool isLetter(string str);
		bool isWholeNum(const string str);
		inline bool fileExists(const string &name);
		void write(string fileName);
		void read(string fileName);
};
