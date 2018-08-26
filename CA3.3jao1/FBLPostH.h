#ifndef H_FBLPostH_H
#define H_FBLPostH_H

#include <iostream>
#include <stdlib.h>
#include "FBLCommentsLLH.h"

using namespace std;

class FBLPost{
	private:
		string writerID;
		string writing;
		string writerLN;
		string writerFN;
		int postID = 0;
		int numComments = 0;
		int numLikes = 0;
		FBLCommentsLL CommentsLL;
	public:
	//	FBLPost* writersPostAddr;
		FBLPost();
		FBLPost(const FBLPost &obj);
		FBLPost(string postInput, string user, int ID, string fn, string ln);
		~FBLPost();

		void thirdMenu(string fn, string ln);

		string getWriting();
		int getNumLikes();
		string getWriterID();
		int getPostID();

		void addNumLikes();
		void setWriter(string user);
		void setPostID(int ID);
};

#endif
