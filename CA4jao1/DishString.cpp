#include <stdio.h>
#include <stdlib.h>
#include "DishStringH.h"

using namespace std;

string DishString:: getString(){
	return str;
}

int DishString:: getAlphaIndex(){
	return alphaIndex;
}

int DishString:: getLengthIndex(){
	return lengthIndex;
}

void DishString:: setString(string s){
	str = s;
}

void DishString:: setAlphaIndex(int index){
	alphaIndex = index;
}

void DishString:: setLengthIndex(int index){
	lengthIndex = index;
}
