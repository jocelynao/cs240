#ifndef H_FBLFriendLLH_H
#define H_FBLFriendLLH_H

#include <iostream>
#include <stdlib.h>
//#include "FBLUserH.h"

using namespace std;

class FBLUser;

class FBLFriendsNode{
	FBLUser *fblFriend;
	FBLFriendsNode *next;
};

class FBLFriendsLL{
	private:
		FBLFriendsNode *head;
		FBLFriendsNode *tail;
	public:
		int length = 0;
};

#endif

