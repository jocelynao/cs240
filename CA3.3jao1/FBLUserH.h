#ifndef FBLUSERH_H
#define FBLUSERH_H

#include <iostream>
#include <stdlib.h>
#include "FBLPostLLH.h"
//#include "FBLFriendLLH.h"
//#include "FBLUserLLH.h"
//#include "FBLUserNodeH.h"
#include <vector>
#include "FBLFeedLLH.h"

using namespace std;

//class FBLFriendsLL;

//class FBLUserLL;
class FBLUserNode;

class FBLUser{
	private:
		FBLUserNode *head;
		string userID;
		string password;
		string firstName;
		string lastName;

		int numPosts = 0;

		FBLFeedLL PostLL;
		FBLPostLL WallLL;
		vector<FBLUser*> friends;
		vector<FBLUser*>:: iterator iter;
		FBLFeedLL FeedLL;
	//	FBLUserNode *nodePtr;
	//	FBLFriendsLL FriendLL;
		
	public:
		FBLUser();
		FBLUser(string id, string pw, string fn, string ln);
		~FBLUser();

		void secondMenu(FBLUserNode *head1);
	//	void thirdMenu(int postID);
		void makeFriend(string friendUser);
		void feed(FBLPost &post);
		void myFriends();
		void goToWall(int ID, string fn, string ln);
	//	void like(FBLPost &post);
	//	void likeFriendsPost(FBLPost &post);
	//	void putComment(FBLPost &post, string comment);

		string getID();
		string getPW();
		string getFN();
		string getLN();
		FBLUserNode* getHeadAddr();
		vector<FBLUser*> &getFriends();
		FBLPostLL &getWallLL();
//		vector<FBLUser*> 

		void setHeadAddr(FBLUserNode *pointer);
		void setID(string id);
		void setPW(string pw);
		void setFN(string fn);
		void setLN(string ln);

};

#endif
