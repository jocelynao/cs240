#include <iostream>
#include <stdlib.h>
#include "FBLCommentH.h"

using namespace std;

FBLComment::FBLComment(){
	comment = "";
}

FBLComment::FBLComment(string com, string fn, string ln){
	comment = com;
	writerFN = fn;
	writerLN = ln;
}

string FBLComment::getComment(){
	return comment;
}

string FBLComment::getFN(){
	return writerFN;
}

string FBLComment::getLN(){
	return writerLN;
}
