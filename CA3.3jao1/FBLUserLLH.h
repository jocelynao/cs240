#ifndef H_FBLUserLLH_H
#define H_FBLUserLLH_H

#include <stdio.h>
#include <stdlib.h>
#include "FBLUserNodeH.h"

using namespace std;

class FBLUserLL{
	private:
		FBLUserNode *head;
	public:
		int length = 0;

		FBLUserLL();
		~FBLUserLL();

		void create(string userid, string pw, string fn, string ln);
		void login(string userid, string pw);
		void users();
		void sortUsers();
		void mergeSort(FBLUserNode *&tempHead, int oriLength);
		FBLUserNode* merge(FBLUserNode *&head1, FBLUserNode *&head2);
};	
	
#endif
