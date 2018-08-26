#ifndef H_DISHSTRING_H
#define H_DISHSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class DishString{
	private:
		string str;
		int alphaIndex;
		int lengthIndex;
	public:
		string getString();
		int getAlphaIndex();
		int getLengthIndex();

		void setString(string s);
		void setAlphaIndex(int index);
		void setLengthIndex(int index);
};

#endif
