#ifndef H_DISHH_H
#define H_DISHH_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "DishStringH.h"

using namespace std;

class Dish{
	private:
		vector<DishString> dishVec;
		vector<int> alphaVec;
		vector<int> lengthVec;

	//	vector<int> *alphaVecPtr = &alphaVec;
	//	vector<int> *lengthVecPtr = &lengthVec;

		int count = 0;
	public:
		~Dish();

		int insert(string s);
		int find(string s);
		bool capitalize(int k);
		bool allcaps(int k);
		bool truncate(int k, int i);
		string getshortest();
		string getfirst();
		void print();

		void alphaSiftUp(int index);
		void lengthSiftUp(int index);

		int getCount();
		vector<DishString> getDishVec();
	
};

#endif
		
