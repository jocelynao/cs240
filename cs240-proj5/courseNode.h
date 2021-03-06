#ifndef CLASSLL_H
#define CLASSLL_H
#include <iostream>
#include <string>
#include <vector>
#include "course.h"

using namespace std;

class node{
	private:
		int postLength = 0;
		int preLength = 0;
		bool taken = false;
		string course;
		string status;
		vector<node*> postReqs;
		vector<node*> preReqs;
	public:
		node(string c, string s);
		node(string c);

		bool checkPR(vector<string> sem);
		void delPreReq(string c);
		void print();

		void addPostReq(node *&ptr);
		void addPreReqs(vector<node*> vecNP);

		string getCourse();
		string getStatus();
		int getPostLength();
		int getPreLength();
		bool getTaken();

		void setStatus(string s);

		~node();

};

/*class courseLL{
	private:
		node *head;
		node *tail;
		int length = 0;
	public:
		void insert(string name, string s);
		void printLL();

		node*& getHead();
		string getHeadCourse();
		int getLength();

		~courseLL();
};*/

#endif
