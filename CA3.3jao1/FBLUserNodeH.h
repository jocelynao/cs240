#ifndef H_FBLUserNodeH_H
#define H_FBLUserNodeH_H

#include <iostream>
#include <stdlib.h>
#include "FBLUserH.h"

using namespace std;

//class FBLUser;

class FBLUserNode{
	public:
		FBLUserNode();

		FBLUser user;
		FBLUserNode *next;
};

#endif

	
