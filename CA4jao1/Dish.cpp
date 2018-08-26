#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <locale>
#include <string>
#include <algorithm>
#include "DishH.h"

using namespace std;

int Dish:: insert(string s){
	DishString dsObj;
	dsObj.setString(s);
	dsObj.setAlphaIndex(count);
	dsObj.setLengthIndex(count);
	dishVec.push_back(dsObj);
	
/*	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getString() << endl;
	}*/

	int index = dishVec.size() - 1;

	alphaVec.push_back(index);
	lengthVec.push_back(index);

	alphaSiftUp(index);
	lengthSiftUp(index);
	
	count = count + 1;
	return dishVec.size() - 1;
}

int Dish:: find(string s){
	int count = -1;
	bool found = false;
	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		count = count + 1;
		if (it -> getString() == s){
		//	cout << "HI" << endl;
		//	cout << count << endl;
			found = true;
			break;
		}
	}
	if (found == false){
	//	cout << "E" << endl;
		count = -1;
	}
//	cout << count << endl;
	return count;
}

bool Dish:: capitalize(int k){
	if (k >= count){
		return false;
	}
	else{
	//	locale loc;
		string kStr = dishVec[k].getString();
		kStr[0] = toupper(kStr[0]);
		dishVec[k].setString(kStr);
	//	cout << "in cap" << endl;

	//	cout << dishVec[k].getString() << endl;
	//	cout << dishVec[k].getAlphaIndex() << endl;
		alphaSiftUp(dishVec[k].getAlphaIndex());
	//	cout << dishVec[k].getString() << endl;
		return true;
	}
}

bool Dish:: allcaps(int k){
	if (k >= count){
		return false;
	}
	else{
		string kStr = dishVec[k].getString();
		transform(kStr.begin(), kStr.end(), kStr.begin(), ::toupper);
	//	cout << kStr << endl;
		dishVec[k].setString(kStr);
		alphaSiftUp(dishVec[k].getAlphaIndex());
		return true;
	}
}

bool Dish::truncate(int k, int i){
	if (k > count){
	//	cout << "here" << endl;
		return false;
	}
	else{
	//	cout << "HIeL" << endl;
		string kStr = dishVec[k].getString();
		if (kStr.length() >= i){
		//	cout << "E" << endl;
		//	int length = kStr.length() - i;
			string shortStr = kStr.substr(0, i);
		//	cout << shortStr << endl;
			dishVec[k].setString(shortStr);

			alphaSiftUp(dishVec[k].getAlphaIndex());
			lengthSiftUp(dishVec[k].getLengthIndex());
		//	cout << shortStr << endl;
			return true;
		}
	}
}

string Dish:: getshortest(){
	int index = lengthVec[0];
	return dishVec[index].getString();
}

string Dish:: getfirst(){
	int index = alphaVec[0];
	return dishVec[index].getString();
}

void Dish:: alphaSiftUp(int index){
	int childIndexA = index;
	bool done = false;
//	string str = "A";
/*	string str2 = "F";
	if (str.compare(str2) < 0){
		cout << "HI" << endl;
	}*/

	if (alphaVec.size() > 1){
	//	cout << "W" << endl;
		while (!done && (childIndexA != 0)){
		//	cout << "E" << endl;
			int parentIndexA = (childIndexA-1)/2;
		//	cout << "CIA: " << childIndexA << endl;
		//	cout << "PIA: " << parentIndexA << endl;


			int childIndexS = alphaVec[childIndexA];
		//	cout << "CIS: " << childIndexS << endl;
			int parentIndexS = alphaVec[parentIndexA];
		//	cout << "PIS: " << parentIndexS << endl;

			string addedString = dishVec[childIndexS].getString();
			string parentString = dishVec[parentIndexS].getString();
		//	cout << "p: " << parentString << endl;
		//	cout << "c: " << addedString << endl;
			if (addedString.compare(parentString) < 0){
			/*	cout << "i" << endl;
				
				for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
				cout << it -> getString() << ", ";
				}
				cout << "\n" << endl;*/

		//		cout << "P: " << dishVec[parentIndex].getAlphaIndex() << endl;
		//		cout << "C: " << dishVec[childIndex].getAlphaIndex() << endl;
	
				int temp = alphaVec[parentIndexA];
				alphaVec[parentIndexA] = alphaVec[childIndexA];
				alphaVec[childIndexA] = temp;
				dishVec[childIndexS].setAlphaIndex(parentIndexA);
				dishVec[parentIndexS].setAlphaIndex(childIndexA);
			//	cout << "P: " << dishVec[parentIndex].getAlphaIndex() << endl;
			//	cout << "C: " << dishVec[childIndex].getAlphaIndex() << endl;

				childIndexA = parentIndexA;
			//	cout << &(alphaVec[0]) << endl;
			}
			else {
			//	cout << "else" << endl;
				done = true;
			}
		//	cout << alphaVec[0] << endl;
		//	cout << alphaVec[1] << endl;
		}
	}

	else{
		dishVec[childIndexA].setAlphaIndex(0);
	}	

/*	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getString() << ", ";
	}
	cout << "\n" << endl;

	cout << "alphaVec: " << endl;
	for (vector<int>:: iterator it = alphaVec.begin(); it != alphaVec.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	cout << "alphaVec indices: " << endl;
	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getAlphaIndex() << ", ";
	}
	cout << "\n" << endl;*/

//	else{
//		dishVec[index].setAlphaPtr(alphaVecPtr);
//	}
}

void Dish:: lengthSiftUp(int index){
	int childIndexL = index;
	bool done = false;
	
	if (lengthVec.size() > 1){
		while (!done && (childIndexL != 0)){
			int parentIndexL = (childIndexL-1)/2;
		//	cout << "CIL: " << childIndexL << endl;
		//	cout << "PIL: " << parentIndexL << endl;

			int parentIndexS = lengthVec[parentIndexL];
			int childIndexS = lengthVec[childIndexL];
		//	cout << "CIS: " << childIndexS << endl;
		//	cout << "PIS: " << parentIndexS << endl;

			string addedString = dishVec[childIndexS].getString();
			string parentString = dishVec[parentIndexS].getString();
		//	cout << "child: " << addedString << endl;
		//	cout << "parent: " << parentString << endl;
			if (addedString.length() < parentString.length()){
			//	cout << "IN if statement for lenght" << endl;
				int temp = lengthVec[parentIndexL];
				lengthVec[parentIndexL] = lengthVec[childIndexL];
				lengthVec[childIndexL] = temp;
				dishVec[childIndexS].setLengthIndex(parentIndexL);
				dishVec[parentIndexS].setLengthIndex(childIndexL);

				childIndexL = parentIndexL;
			//	dishVec[index] = parentString;
			}
			else {
				done = true;
			}
		}
	}
	else{
		dishVec[childIndexL].setLengthIndex(0);
	}	

/*	cout << "lengthVec: " << endl;
	for (vector<int>:: iterator it = lengthVec.begin(); it != lengthVec.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	cout << "lengthVec indices: " << endl;
	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getLengthIndex() << ", ";
	}
	cout << "\n" << endl;*/
}

void Dish:: print(){
	cout << "--------------------------------------" << endl;

	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getString() << ", ";
	}
	cout << "\n" << endl;

	cout << "alphaVec: " << endl;
	for (vector<int>:: iterator it = alphaVec.begin(); it != alphaVec.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	cout << "alphaVec indices: " << endl;
	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getAlphaIndex() << ", ";
	}
	cout << "\n" << endl;

	cout << "lengthVec: " << endl;
	for (vector<int>:: iterator it = lengthVec.begin(); it != lengthVec.end(); it++){
		cout << *it << ", ";
	}
	cout << "\n" << endl;

	cout << "lengthVec indices: " << endl;
	for (vector<DishString>:: iterator it = dishVec.begin(); it != dishVec.end(); it++){
		cout << it -> getLengthIndex() << ", ";
	}
	cout << "\n" << endl;


	cout << "-----------------------------------------" << endl;
}

vector<DishString> Dish:: getDishVec(){
	return dishVec;
}

int Dish:: getCount(){
	return count;
}

Dish:: ~Dish(){
}
