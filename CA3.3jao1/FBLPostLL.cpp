#include <stdio.h>
#include <stdlib.h>
#include "FBLPostLLH.h"

using namespace std;

FBLPostLL::FBLPostLL(){
	head = NULL;
	tail = NULL;
}

void FBLPostLL:: postAction(int feedsPostID, string fn, string ln){
	FBLPostNode *nodePtr = head;
//	cout << head -> post.getWriting() << endl;
	while (nodePtr != NULL){
		if (nodePtr -> post.getPostID() == feedsPostID){
		//	cout << "1: " << nodePtr -> post.getPostID() << endl;

		//	cout << "2: " << feedsPostID << endl;
			nodePtr -> post.thirdMenu(fn, ln);
			break;
		}
		nodePtr = nodePtr -> next;
	}
//	cout << "num likes in feed: " << nodePtr -> post.getNumLikes() << endl;
}

/*void FBLPostLL::thirdMenu(int feedsPostID){
	string command;
	string str;
	string comment;

	FBLPost &ownersPost = findPost(feedsPostID);

	FBLPostNode *nodePtr = head;

	while (true){
		cout << "What would you like to do with the post? Please enter a command (LIKE, COMMENT, READ_AZ, READ_ZA, or DONE): ";
		getline(cin, str);
		command = str.substr(0, str.find(' '));
	//	cout << post.getNumLikes() << endl;
	//	cout << post.getNumLikes() + 1 << endl;
		if (str == "LIKE"){
		//	findPost(feedsPostID).addNumLikes();
			ownersPost.addNumLikes();
			cout << "Number of likes on this post : " << ownersPost.getNumLikes() << endl;
		//	cout << "findpost likes: " << findPost(feedsPostID).getNumLikes() << endl;
		}
		else if (command == "COMMENT"){
			comment = str.substr(str.find(" ") + 1);
			ownersPost.addComment(comment);
		}
		else if (command == "DONE"){
		//	cout << "E" << endl;
			break;
		}
		else{
			cout << "Sorry, that was an invalid command" << endl;
		}
	}
}*/

FBLPost FBLPostLL::post(string &postInput, string user, int postID, string fn, string ln){
	FBLPostNode *newNode = new FBLPostNode();
	FBLPost newPost(postInput, user, postID, fn, ln);
//	cout << "1: " << newPost.getWriting() << endl;
	
	newNode -> post = newPost;
	newNode -> next = NULL;
//	newNode -> post.setWriter(user);
//	newNode -> post.setPostID(postID);
/*	newNode -> post.addNumLikes();
	newNode -> post.addNumLikes();
	newNode -> post.addNumLikes();*/
//	cout << "num likes: " << newNode -> post.getNumLikes() << endl;

	if (head == NULL){
	//	cout << "M" << endl;
		head = newNode;
		tail = newNode;
		length = length + 1;
	}
	else{

		tail -> next = newNode;
		tail = newNode;
		length = length + 1;
	}
	FBLPost copyPost = newNode -> post;
/*	if (head == NULL){
		cout << "head isnull" << endl;
	}*/

/*	for (int i = 0; i < length; i++){
		cout << nodePtr -> post.getWriting() << endl;
		nodePtr = nodePtr -> next;
	}
	*/
	//cout << newPost.getWriting()<< endl;
	return (copyPost);
}

/*void FBLPostLL::read(){
	if (head == NULL){
		cout << "Nothing to read" << endl;
	}
	else{
		FBLPostNode *nodePtr = head;
	//	cout << "HI" << endl;
		for(int i = 0; i < postIndex; i++){
			nodePtr = nodePtr -> next;
		}
		cout << nodePtr -> post.getWriting() << endl;
		postIndex = postIndex + 1;
	
	//	cout << "entering read" << endl;
		FBLPostNode *nodePtr = head;
		cout << head -> post.getWriterID() << "'s post: " << head -> post.getWriting() << endl;
		head = head -> next;

		delete nodePtr;
		nodePtr = NULL;
		length = length - 1;

	}
}*/

void FBLPostLL::wall(){
/*	if (head == NULL){
		cout << "E" << endl;
	}*/
	FBLPostNode *nodePtr = head;
//	cout << head -> post.getWriting() << endl;
//	cout << nodePtr -> post.getWriting() << endl;
	while (nodePtr != NULL){
		cout << nodePtr -> post.getWriterID() << "'s post: " << nodePtr -> post.getWriting() << " with " << nodePtr -> post.getNumLikes() << " likes" << endl;
	//	cout << nodePtr -> post.getPostID() << endl;
		nodePtr = nodePtr -> next;
	}
}

FBLPostNode *FBLPostLL:: getHeadAddr(){
	return head;
}

FBLPostLL::~FBLPostLL(){
	for (int i = 0; i < length; i++){
		FBLPostNode *nodePtr = head;
		head = head -> next;
		delete nodePtr;
		nodePtr = NULL;
	}
}

