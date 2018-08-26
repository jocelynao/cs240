#include <stdio.h>
#include <stdlib.h>
#include "FBLUserLLH.h"

using namespace std;

FBLUserLL::FBLUserLL(){
	head = NULL;
}

void FBLUserLL::create(string userid, string pw, string fn, string ln){
	FBLUserNode *nodePtr = head;

	FBLUserNode *newNode = new FBLUserNode();
	FBLUser newUser(userid, pw, fn, ln);

	newNode -> user = newUser;
	newNode -> next = NULL;
	if (head == NULL){
		head = newNode;
		newNode -> user.setHeadAddr(head);
		length = length + 1;
	}

	else {
		if (head -> next == NULL){
			if ((head -> user.getID()) == userid){
				delete newNode;
				cout << "Sorry. That username is taken. Please create another one" << endl;
			}
			else{
			//	cout << "second" << endl;
				newNode -> user.setHeadAddr(head);
			//	cout << newNode -> user.getHeadAddr() << endl;
				nodePtr -> next = newNode;
				nodePtr = nodePtr -> next;

				length = length + 1;
		//		cout << nodePtr -> user.getID() << endl;
		//		cout << "end here" << endl;
			}
			
		}

		else{
			bool userFound = false;
		//	cout << "third" << endl;
			while (nodePtr -> next != NULL){
		//		cout << "HI" << endl;
				if ((nodePtr -> user.getID() == userid) ||
						(nodePtr -> next -> user.getID() == userid)){
					cout << "Sorry. That username is taken. Please create another one" << endl;
					userFound = true;
					delete newNode;
					break;
				}
				nodePtr = nodePtr -> next;
			}
			if (!userFound){
				newNode -> user.setHeadAddr(head);
				nodePtr -> next = newNode;
				length = length + 1;
			}
		}
	}
//	cout << length << endl;
//	cout << "EH" << endl;
	nodePtr = NULL;
//	cout << "WHY" << endl;
//	for (int i = 0; i < length; i++){
//		cout << nodePtr -> user.getID() << endl;
//		nodePtr = nodePtr -> next;
//	}

	
}

void FBLUserLL::login(string userid, string pw){
	FBLUserNode *nodePtr = head;

	bool opDone = false;
	bool userFound = false;
	if (head != NULL){
		while (!opDone){
			if (nodePtr -> user.getID() == userid){
				userFound = true;
				if (nodePtr -> user.getPW() == pw){
				//	cout << head << endl;
					nodePtr -> user.secondMenu(head);
				}
				else{
					cout << "Invalid password. Please try logging in again" << endl;
				}
				opDone = true;
			}
			else{
				if (nodePtr -> next != NULL){
					nodePtr = nodePtr -> next;
				}
				else{
					opDone = true;
				}
			}
		}
	}
	if (!userFound){
		cout << "User not found in the system. Please try logging in again" << endl;
	}
}

void FBLUserLL::users(){
	if (head != NULL){
		FBLUserNode *nodePtr = head;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			cout << nodePtr -> user.getFN();
			cout << " <" << nodePtr -> user.getID() << ">" << endl;
			nodePtr = nodePtr -> next;
		}
	}
	else{
		cout << "There are no users" << endl;
	}
}

void FBLUserLL::sortUsers(){
	FBLUserNode *nodePtr = head;
/*	while (nodePtr != NULL){
		cout << nodePtr -> user.getLN() << ", ";
		nodePtr = nodePtr -> next;
	}
	cout << "\nexiting sortusers()" << endl;*/

	mergeSort(head, length);
}

FBLUserNode* FBLUserLL::merge(FBLUserNode *&head1, FBLUserNode *&head2){
//	cout << "a" << endl;
//	cout << "--------------------------------------------" << endl;
//	cout << "merging lists" << endl;
	FBLUserNode *headTemp1;
	FBLUserNode *headTemp2;
	FBLUserNode *temp3;
//	cout << head1 -> user.getLN() << endl;
//	cout << head2 -> user.getLN() << endl;
	
//	cout << "E" << endl;
	FBLUserNode *np = head1;
//	cout << "head1 in beginning: ";
/*	while (np != NULL){
		cout << np -> user.getLN() << ", ";
		np = np -> next;
	//	cout << "E" << endl;
	}*/
//	cout << "\nEEW" << endl;
//	cout << "\nhead2 in beginning: ";
	np = head2;
//	cout << "W" << endl;
/*	while (np != NULL){
	//	cout << "REW" << endl;
		cout << np -> user.getLN() << ", ";
		np = np -> next;
	}*/
//	cout << "\n" << endl;

	if (head1 == NULL){
	//	cout << "b" << endl;
		return head2;
	}
	if (head2 == NULL){
	//	cout << "c" << endl;
		return head1;
	}

	headTemp1 = head1;
//	cout << "REWRW" << endl;
//	bool foundPlace = false;

	while (head2 != NULL){
		bool foundPlace = false;
	//	cout << "PEWE" << endl;

		headTemp2 = head2;
		head2 = head2 -> next;
		headTemp2 -> next = NULL;

		
	//	cout << "headTemp1: " << headTemp1 -> user.getLN() << endl;
	//	cout << "headTemp2: " << headTemp2 -> user.getLN() << endl;
		
		if ((head1 -> user.getLN()).compare(headTemp2 -> user.getLN()) > 0){
		//	cout << "f" << endl;
		//	cout << "putting " << headTemp2 -> user.getLN() << " before " << head1 -> user.getLN() << endl;
			headTemp2 -> next = head1;
			head1 = headTemp2;
			headTemp1 = head1;
		}	
		else{
		//	cout << "2" << endl;
			while (!foundPlace){
			//	cout << "2.5" << endl;
			//	cout << "EW" << endl;
				if (headTemp1 -> next != NULL){
				//	cout << "3" << endl;
					if (((headTemp1 -> next) -> user.getLN()).compare(headTemp2 -> user.getLN()) <= 0){
				//		cout << "moving on to next headTemp1 variable" << endl;
						headTemp1 = headTemp1 -> next;
					}
					else{//
					//	cout << "placing " << headTemp2 -> user.getLN() << " before " << headTemp1 -> user.getLN() << endl;
						temp3 = headTemp1 -> next;
						headTemp1 -> next = headTemp2;
						headTemp2 -> next = temp3;
						foundPlace = true;
					}
				}
				else{
				//	cout << "headTemp1 -> next == NULL" << endl;
					headTemp1 -> next = headTemp2;
					headTemp1 = headTemp1 -> next;
					foundPlace = true;
				}
			/*	if (headTemp1 -> next == NULL){
					headTemp1 -> next = headTemp2;
					headTemp1 = headTemp1 -> next;
				}
				else if (((headTemp1 -> next) -> user.getLN()).compare(headTemp2 -> user.getLN()) <= 0){
				//	cout << "h" << endl;
					headTemp1 = headTemp1 -> next;
				}
				else{
					temp3 = headTemp1 -> next;
					headTemp1 -> next = headTemp2;
					headTemp2 -> next = temp3;
				}*/
			}
		}
	}
/*	cout << "\nmerged lists" << endl;
	np = head1;
	cout << "head1 in end: ";
	while (np != NULL){
		cout << np -> user.getLN() << ", ";
		np = np -> next;
	}

	cout << "\nhead2 in end: " << endl;
	np = head2;
	while (np != NULL){
		cout << np -> user.getLN() << ", ";
		np = np -> next;
	}
	cout << "---------------------------------------------" << endl;*/
	return head1;
}

void FBLUserLL::mergeSort(FBLUserNode *&tempHead, int oriLength){
	FBLUserNode *firstHead = tempHead;
	FBLUserNode *secondHead = tempHead;
	FBLUserNode *splitHead = tempHead;
	
	FBLUserNode *nodePtr = head;
	cout << "actual list: ";
/*	while (nodePtr != NULL){
		cout << nodePtr -> user.getLN() << ", ";
		nodePtr = nodePtr -> next;
	}
	cout << "\n";
	nodePtr = tempHead;
	cout << "list to be split: ";
	while (nodePtr != NULL){
		cout << nodePtr -> user.getLN() << ", ";
		nodePtr = nodePtr -> next;
	}
	cout << "\n" << endl;*/

	if (oriLength < 2){
		return;
	}
	else{
		int lengthFirstHalf = oriLength/2;
	//	cout << lengthFirstHalf << endl;
		int lengthSecondHalf = oriLength - lengthFirstHalf;

		for (int i = 0; i < lengthFirstHalf; i++){
			splitHead = secondHead;
			secondHead = secondHead -> next;
		}
		splitHead -> next = NULL;

		nodePtr = firstHead;
	/*	cout << "first half: ";
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\nsecond half: ";
		nodePtr = secondHead;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\n" << endl;*/


		mergeSort(firstHead, lengthFirstHalf);
		mergeSort(secondHead, lengthSecondHalf);

	//	cout << "after completely splitting first half and second half" << endl;

	/*	nodePtr = firstHead;
		cout << "first half: ";
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\nsecond half: ";
		nodePtr = secondHead;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\n" << endl;

		cout << "merged list at end of whole function: ";
		nodePtr = tempHead;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\n" << endl;*/


		tempHead = merge(firstHead, secondHead);
		head = tempHead;

	/*	nodePtr = firstHead;
		cout << "first half: ";
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\nsecond half: ";
		nodePtr = secondHead;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\n" << endl;

		cout << "merged list at end of whole function: ";
		nodePtr = tempHead;
		while (nodePtr != NULL){
			cout << nodePtr -> user.getLN() << ", ";
			nodePtr = nodePtr -> next;
		}

		cout << "\n" << endl;*/
	}
}

FBLUserLL::~FBLUserLL(){
	if (head != NULL){
	//	cout << "L" << endl;
		while (head -> next != NULL){
			FBLUserNode *nodePtr = head;
			head = head -> next;
		//	cout << "E" << endl;
			delete nodePtr;
		//	cout << "HI" << endl;
			nodePtr = NULL;
		}
		delete head;
		head = NULL;
	}
	
}

