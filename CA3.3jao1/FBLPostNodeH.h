#ifndef H_FBLPostNode_H
#define H_FBLPostNode_H

#include <iostream>
#include <stdlib.h>
#include "FBLPostH.h"

using namespace std;

class FBLPostNode{
	public:
		FBLPostNode();

		FBLPost post;
		FBLPostNode *next;
};

#endif


