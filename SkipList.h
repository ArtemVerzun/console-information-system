#ifndef SKIPLIST_HEADER
#define SKIPLIST_HEADER
#ifndef NODESKIPLIST_HEADER
#define NODESKIPLIST_HEADER


#include "Client.h"
#include "Check.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "Card.h"
//using namespace std;

//struct NodeSkipList {
//	string a;
//	string title;
//	NodeSkipList* next;
//	NodeSkipList* skip;
//};
//
//class SkipList {
//public:
//	NodeSkipList* root;
//
//	SkipList() {
//		root = NULL;
//	}
//
//	void insert() {
//		string a = "";
//		cin >> a;
//		
//		//root=null
//		if (root == NULL) {
//			root = new NodeSkipList();
//			root->a = a;
//			root->title = a[0];
//			root->next = NULL;
//			root->skip = NULL;
//		}
//		else {
//			//no skip
//			if (a[0] = root->a[0]) {
//				NodeSkipList* temp = root;
//				while (temp->next != NULL) {
//					if (temp->next->a[0] == a[0]) {
//						break;
//					}
//					temp = temp->next;
//				}
//				NodeSkipList* next = new NodeSkipList();
//				next->a = a;
//				next->next = temp->skip;
//				temp->next = next;
//			}
//			//skip
//			else {
//				NodeSkipList* temp = root;
//				while (temp->skip != NULL) {
//					if (temp->skip->a[0] == a[0]) {
//						break;
//					}
//					temp = temp->skip;
//				}
//				//title==a
//				)
//			}
//		}
//	}
//	void view();
//
//};

struct nodeSkipList {
	Client* client;
	Card* card;
	nodeSkipList* next;
	nodeSkipList* nextSkip;
	int title;
};

class SkipList {
public:

	nodeSkipList* root;
	HashTable* table;
	AVLTree* tree;
	int length;
	SkipList(AVLTree* tree, HashTable* table);
	void addNode();
	void addNode(Client* client, Card* card);
	void removeNode();
	void viewList();
	int findByPassport();
	bool findByCard();
	int findByPassport(string);
	bool findByCard(string);

	nodeSkipList* quicksort(nodeSkipList* start, int len);

	void sort();

};

#endif
#endif