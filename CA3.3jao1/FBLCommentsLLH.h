#include <iostream>
#include <stdlib.h>
#include "FBLCommentH.h"

using namespace std;

class FBLCommentsNode{
	public:
		FBLComment comment;
		FBLCommentsNode *next = NULL;
		FBLCommentsNode *prev = NULL;
};

class FBLCommentsLL{
	private:
		FBLCommentsNode *head;
		FBLCommentsNode *tail;
	public:
		int length = 0;

		void insert(string com, string fn, string ln);
		void readAZ();
		void readZA();

		FBLCommentsLL();
		~FBLCommentsLL();
};
