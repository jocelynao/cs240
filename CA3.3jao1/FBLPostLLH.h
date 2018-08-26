#ifndef H_FBLPostLLH_H
#define H_FBLPostLLH_H

#include <iostream>
#include <stdlib.h>
#include "FBLPostNodeH.h"

using namespace std;

class FBLPostLL{
	private:
		FBLPostNode *head;
		FBLPostNode *tail;
		int postIndex = 0;
	public:
		int length = 0;

		FBLPostLL();

		~FBLPostLL();
		FBLPost post(string &postInput, string user, int postID, string fn, string ln);
		void postAction(int feedsPostID, string fn, string ln);
		void read();
		void wall();

		FBLPostNode *getHeadAddr();

};

#endif
