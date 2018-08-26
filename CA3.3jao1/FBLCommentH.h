#include <iostream>
#include <stdlib.h>

using namespace std;

class FBLComment{
	private:
		string comment;
		string writerFN;
		string writerLN;
	public:
		FBLComment();
		FBLComment(string com, string fn, string ln);

		string getComment();
		string getFN();
		string getLN();
};
