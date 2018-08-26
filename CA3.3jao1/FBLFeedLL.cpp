#include <iostream>
#include <stdlib.h>
#include "FBLFeedLLH.h"

FBLFeedLL::FBLFeedLL(){
	head = NULL;
	tail = NULL;
}

void FBLFeedLL::insert(FBLPost &writersPost){
//	cout << "In insert" << endl;
	//cout << i << endl;
	FBLPostNode *newNode = new FBLPostNode();
	FBLPost newPost(writersPost);
	newNode -> post = newPost;
	newNode -> next = NULL;
/*	cout << "address of feed's address of node post: " << &(newNode -> post): << endl;
	cout << "address of feed's address of node post: " << &newNode << endl;
	cout << "address of feed's post: " << &newPost << endl;*/
//	cout <<  newNode -> post.getWriting() << endl;

	if (head == NULL){
		head = newNode;
		tail = newNode;
		length = length + 1;
	}
	else{
		if (length == 1){
			head -> next = newNode;
		}
		tail -> next = newNode;
		tail = newNode;
		length = length + 1;
	}
}

void FBLFeedLL::myFeed(){
	FBLPostNode *nodePtr = head;
	if (nodePtr == NULL){
		cout << "Sorry, there are no posts to read" << endl;
	}
	while (nodePtr != NULL){
	//	cout << "E" << endl;
		cout << nodePtr -> post.getWriterID() << "'s post: " <<  nodePtr -> post.getWriting() << endl;
		nodePtr = nodePtr -> next;
	}
}

vector<string> FBLFeedLL::read(){
/*	FBLPostNode *nodePtr = head;
	for(int i = 0; i < readIndex; i++){
		nodePtr = nodePtr -> next;
	}
	cout << nodePtr -> post.getWriting() << endl;
//	cout << "address of feed's node post: " << &(nodePtr -> post) << endl;
	readIndex = readIndex + 1;
	cout << "I" << endl;
	return (nodePtr -> post);*/
//	cout << "entering read()" << endl;
	vector<string> userInfo;

	FBLPostNode *nodePtr = head;
//	cout << "Length: " << length << endl;
	cout << head -> post.getWriterID() << "'s post: " << head -> post.getWriting() << endl;
	userInfo.push_back(head -> post.getWriterID());
	userInfo.push_back(to_string(head -> post.getPostID()));
//	userInfo.push_back(post.getPostID()) << endl;

//	string hi =  userInfo.pop_back();

	head = head -> next;
//	cout << head -> post.getWriting() << endl;
	delete nodePtr;
	nodePtr = NULL;
	length = length - 1;
//	cout << "exitting read" << endl;
	return (userInfo);
}

FBLFeedLL::~FBLFeedLL(){
	for (int i = 0; i < length; i++){
		FBLPostNode *nodePtr = head;
		head = head -> next;
		delete nodePtr;
		nodePtr = NULL;
	}
	head = NULL;
	tail = NULL;
}
