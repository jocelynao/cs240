#include <iostream>
#include <stdlib.h>
#include "FBLPostH.h"

using namespace std;

FBLPost::FBLPost(){
	writing = "";
	writerID = "";
	postID = 0;
}

FBLPost::FBLPost(const FBLPost &obj){
	writerID = obj.writerID;
	writing = obj.writing;
	postID = obj.postID;
}

FBLPost::FBLPost(string postInput, string user, int ID, string fn, string ln){
	writing = postInput;
	writerID = user;
	postID = ID;
	writerLN = ln;
	writerFN = fn;
}

void FBLPost::thirdMenu(string fn, string ln){
	string command;
	string str;
	string comment;
//	cout << writing << endl;

	while (true){
		cout << "What would you like to do with the post? Please enter a command (LIKE, COMMENT<text>, READ_AZ, READ_ZA, or DONE): ";
		getline(cin, str);
		command = str.substr(0, str.find(' '));
	//	cout << post.getNumLikes() << endl;
	//	cout << post.getNumLikes() + 1 << endl;
		if (str == "LIKE"){
		//	findPost(feedsPostID).addNumLikes();
			addNumLikes();
			cout << "Number of likes on this post : " << getNumLikes() << endl;
		//	cout << "findpost likes: " << findPost(feedsPostID).getNumLikes() << endl;
		}
		else if (command == "COMMENT"){
			comment = str.substr(str.find(" ") + 1);
			CommentsLL.insert(comment, fn, ln);
		}
		else if (command == "READ_AZ"){
			CommentsLL.readAZ();
	}
		else if (command == "READ_ZA"){
			CommentsLL.readZA();
		}
		else if (command == "DONE"){
		//	cout << "E" << endl;
			break;
		}
		else{
			cout << "Sorry, that was an invalid command" << endl;
		}
	}
}

string FBLPost::getWriting(){
	return writing;
}

string FBLPost::getWriterID(){
	return writerID;
}

int FBLPost::getNumLikes(){
	return numLikes;
}

int FBLPost::getPostID(){
	return postID;
}

void FBLPost::addNumLikes(){
	numLikes = numLikes + 1;
}

void FBLPost::setWriter(string user){
	writerID = user;
}

void FBLPost::setPostID(int ID){
	postID = ID;
}

FBLPost::~FBLPost(){
}

