#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "FBLUserH.h"
#include "FBLUserNodeH.h"

using namespace std;

FBLUser::FBLUser(){
	head = NULL;
	userID = "";
	password = "";
	firstName = "";
	lastName = "";
}

FBLUser::FBLUser(string id, string pw, string fn, string ln){
	userID = id;
	password = pw;
	firstName = fn;
	lastName = ln;
}

void FBLUser::secondMenu(FBLUserNode *head1){
	//cout << head -> user.getID() << "RE" << endl;
//	cout << &PostLL << endl;
//	cout << &WallLL << endl;
//	cout << head << endl;
//	cout << WallLL.getHeadAddr() << endl;
	string str;
	string command;
	string postInput;
	string friendUser;
//	cout << head1 << endl;
//	cout << head << endl;	
	while (true){
		cout << "Please enter a command (POST <text>, READ, FRIEND <userid>, MYFRIENDS, MYFEED, MYWALL, LOGOUT): ";
		str = "";
		getline(cin, str);
		command = str.substr(0, str.find(' '));

		if (command == "POST"){
			postInput = str.substr(str.find(" ") + 1);
		//	cout << postInput << endl;
			FBLPost newPost = WallLL.post(postInput, userID, numPosts, firstName, lastName);
		//	cout << "address of writer's post: " << &newPost << endl;
		//	cout << newPost.getNumLikes() << endl;

		//	PostLL.post(postInput, userID, numPosts);
		//	cout << "RE" << endl;
		//	cout << newPost.getWriting() << endl;
		//	cout << "E" << endl;
			feed(newPost);
		
			numPosts = numPosts + 1;
	
		//	cout << newPost.getPostID() << endl;
		}
		else if (command == "READ"){
		//	cout << FeedLL.length << endl;
		//	cout << FeedLL.readIndex << endl;
			//cout << FeedLL.length
			if (PostLL.length > 0){
				vector<string> userInfo = PostLL.read();
			//	cout << "what" << endl;
			//	cout << "address of feed's post: " << &feedPost << endl;
			//	cout << feedPost.getNumLikes() << endl;

				FBLUserNode *nodePtr = head;
				string owner = userInfo[0];
				int postID = stoi(userInfo[1]);

			//	cout << "2" << endl;
				bool done = false;
				while (nodePtr != NULL && !done){
					if (nodePtr -> user.getID() == owner){
					//	cout << "I" << endl;
						nodePtr -> user.goToWall(postID, firstName, lastName);
						done = true;
						//nodePtr -> user.getWallLL().thirdMenu(postID);
					}
					nodePtr = nodePtr -> next;
				}		
					
			}
			else{
				cout << "Nothing to read" << endl;
			}
		}
		else if (command == "FRIEND"){
			friendUser = str.substr(str.find(" ") + 1);
			makeFriend(friendUser);
		}
		else if (command == "MYFEED"){
			FeedLL.myFeed();
		/*	for (iter = friends.begin(); iter != friends.end(); iter++){
				iter -> FeedLL.myFeed();	
			}	*/		
		}
		else if (command == "MYFRIENDS"){
			myFriends();
		}
		else if (command == "MYWALL"){
			WallLL.wall();
		}
		else if (command == "LOGOUT"){
			break;
		}
	/*	else if (command == "SETNAME"){
			for (iter = friends.begin(); iter != friends.end(); iter++){
				iter -> setFN("JOCELYN");	
			}	
		}*/
	/*	else if(command == "GETNAME"){
			cout << getFN() << endl;
		}*/
		else{
			cout << "Sorry, that was an invalid command" << endl;
		}
	}
}

void FBLUser::makeFriend(string friendUser){
	FBLUserNode *nodePtr = head;
	bool madeFriend = false;
	if (friendUser == userID){
		cout << "You cannot friend yourself" << endl;
	}
	else{
		for (iter = friends.begin(); iter != friends.end(); iter++){
			if ((*iter) -> getID() == friendUser){
				cout << "You already friended this user" << endl
;
				madeFriend == true;
				break;
			}
		}
		if (iter == friends.end()){
			while (nodePtr != NULL){
				if (nodePtr -> user.getID() == friendUser){
					friends.push_back(&(nodePtr -> user));
					FBLUser *FBLPointer = this;
					nodePtr -> user.getFriends().push_back(FBLPointer);
				
									
					madeFriend = true;
					cout << "User friended" << endl;
					break;
				}
				nodePtr = nodePtr -> next;
			}
			if (!madeFriend){
				cout << "User does not exist" << endl;
			}
		}
		}
}

void FBLUser::feed(FBLPost &post){
	for (iter = friends.begin(); iter != friends.end(); iter++){
		(*iter) -> FeedLL.insert(post);
		(*iter) -> PostLL.insert(post);
	}
}

void FBLUser::myFriends(){
	if (friends.empty()){
		cout << "Sorry, you have no friends :(" << endl;
	}
	else{
		for (iter = friends.begin(); iter != friends.end(); iter++){
			cout << (*iter) -> getFN() << " " << (*iter) -> getLN() << endl;
		}
	}
}

void FBLUser::goToWall(int postID, string fn, string ln){
	WallLL.postAction(postID, fn, ln);
}

/*void FBLUser::thirdMenu(int postID){
	string command;
	string str;
	string comment;

	FBLUserNode *nodePtr = head;

	while (true){
		cout << "What would you like to do with the post? Please enter a command (LIKE, COMMENT, READ_AZ, READ_ZA, or DONE): ";
		getline(cin, str);
		command = str.substr(0, str.find(' '));
	//	cout << post.getNumLikes() << endl;
	//	cout << post.getNumLikes() + 1 << endl;
		if (str == "LIKE"){
			cout << "HI" << endl;
		}
		else if (command == "COMMENT"){
			comment = str.substr(str.find(" ") + 1);
		//	putComment(post, comment);
		}
		else if (command == "DONE"){
			break;
		}
		else{
			cout << "Sorry, that was an invalid command" << endl;
		}
	}
}*/

/*void FBLUser::likeFriendsPost(FBLPost &post){
	FBLUserNode *nodePtr = head;
	cout << "1" << endl;
	string owner = post.getWriter();
	int ID = post.getPostID();
	cout << "2" << endl;
	bool done = false;
	while (nodePtr != NULL || !done){
		if (nodePtr -> user.getID() == owner){
			cout << "3" << endl;
			FBLPostLL ownersWall = nodePtr -> user.getWallLL();
			FBLPostNode *wallPtr = ownersWall.getHeadAddr();
			cout << "4" << endl;
			while (wallPtr != NULL){
				if (wallPtr -> post.getPostID() == ID){
					cout << "5" << endl;
					cout << wallPtr -> post.getWriting() << endl;
				//	wallPtr = NULL;
					cout << "address of supposedly writer's post: "<< &(wallPtr -> post) << endl;
					done = true;
					cout << "5.5" << endl;
				//	break;
					cout << "5.6" << endl;
				}
				cout << "6" << endl;
				wallPtr = wallPtr -> next;
			}
		}
		cout << "7" << endl;
		nodePtr = nodePtr -> next;
	}
	cout << "8" << endl;
	nodePtr = NULL;
}*/

string FBLUser::getID(){
	return userID;
}

string FBLUser::getPW(){
	return password;
}

string FBLUser::getFN(){
	return firstName;
}

string FBLUser::getLN(){
	return lastName;
}

FBLUserNode* FBLUser::getHeadAddr(){
	return head;
}

vector<FBLUser*> &FBLUser:: getFriends(){
	return friends;
}

FBLPostLL &FBLUser:: getWallLL(){
	return WallLL;
}

void FBLUser::setHeadAddr(FBLUserNode *pointer){
	head = pointer;
}

void FBLUser::setID(string id){
	userID = id;
}

void FBLUser::setPW(string pw){
	password = pw;
}

void FBLUser::setFN(string fn){
	firstName = fn;
}

void FBLUser::setLN(string ln){
	lastName = ln;
}

FBLUser::~FBLUser(){
//	delete PostLL;
//	PostLL = NULL;
}


