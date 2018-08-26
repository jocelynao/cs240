#ifndef H_FBLFeedLLH_H
#define H_FBLFeedLLH_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "FBLPostNodeH.h"
#include <vector>

using namespace std;

/*class FBLFeedNode{
	public:
		FBLPost post;
		FBLFeedNode *next;
};*/

class FBLFeedLL{
	private:
		FBLPostNode *head;
		FBLPostNode *tail;
	public:
		int length = 0;
		int readIndex = 0;
		FBLFeedLL();
		~FBLFeedLL();
		
		void insert(FBLPost &writersPost);
		void myFeed();
		vector<string> read();
};

#endif
