#include "SkipList.h"

SkipList::SkipList(AVLTree* tree, HashTable* table) {
	root = NULL;
	this->tree = tree;
	this->table = table;
	length = 0;
}

void SkipList::addNode() {
	Client* client = NULL;
	Card* card = NULL;
	while (true) {
		client = tree->findId();
		if (client != NULL) {
			break;
		}
		else {
			cout << "Такой клиент не найден, повторите ввод: ";
		}
	}
	while (true) {
		card = table->searchId();
		if (card != NULL) {
			break;
		}
		else {
			cout << "Такая карта не найдена, повторите ввод: ";
		}
	}
	if (!card->availability) {
		cout << "Карта уже выдана";
		return;
	}
	
	if (root == NULL) {
		root = new nodeSkipList();
		root->card = card;
		root->client = client;
		root->next = NULL;
		root->nextSkip = NULL;
		root->title = card->id[0];
		root->client->countCards++;
		length++;
		root->card->availability = false;
	}
	else {
		nodeSkipList* temp = root;
		while (card->id[0] != temp->title) {
			if (temp->nextSkip == NULL) {
				nodeSkipList* nextNode = new nodeSkipList();
				nextNode->card = card;
				nextNode->client = client;
				nextNode->next = NULL;
				nextNode->nextSkip = NULL;
				nextNode->title = card->id[0];
				temp->nextSkip = nextNode;
				nextNode->client->countCards++;
				nextNode->card->availability = false;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = nextNode;
				length++;
				return;
			}
			else {
				temp = temp->nextSkip;
			}	
		}

		nodeSkipList* temp2 = temp;
		while (temp2->next != NULL && card->id[0] == temp2->next->card->id[0]) {
			temp2 = temp2->next;
		}
		nodeSkipList* nextNode = new nodeSkipList();
		nextNode->card = card;
		nextNode->client = client;

		nextNode->next = temp->nextSkip;
		nextNode->nextSkip = NULL;
		nextNode->title = -1;
		nextNode->client->countCards++;
		nextNode->card->availability = false;
		temp2->next = nextNode;
		length++;
	}
}

void SkipList::addNode(Client* client, Card* card) {

	if (root == NULL) {
		root = new nodeSkipList();
		root->card = card;
		root->client = client;
		root->next = NULL;
		root->nextSkip = NULL;
		root->title = card->id[0];
		root->client->countCards++;
		length++;
		root->card->availability = false;
	}
	else {
		nodeSkipList* temp = root;
		while (card->id[0] != temp->title) {
			if (temp->nextSkip == NULL) {
				nodeSkipList* nextNode = new nodeSkipList();
				nextNode->card = card;
				nextNode->client = client;
				nextNode->next = NULL;
				nextNode->nextSkip = NULL;
				nextNode->title = card->id[0];
				temp->nextSkip = nextNode;
				nextNode->client->countCards++;
				nextNode->card->availability = false;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = nextNode;
				length++;
				return;
			}
			else {
				temp = temp->nextSkip;
			}
		}

		nodeSkipList* temp2 = temp;
		while (temp2->next != NULL && card->id[0] == temp2->next->card->id[0]) {
			temp2 = temp2->next;
		}
		nodeSkipList* nextNode = new nodeSkipList();
		nextNode->card = card;
		nextNode->client = client;

		nextNode->next = temp->nextSkip;
		nextNode->nextSkip = NULL;
		nextNode->title = -1;
		nextNode->client->countCards++;
		nextNode->card->availability = false;
		temp2->next = nextNode;
		length++;
	}
}

void SkipList::viewList() {
	nodeSkipList* temp = root;
	while (temp != NULL) {
		temp->client->viewClient();
		temp->card->viewCard();
		temp = temp->next;
	}
}

void SkipList::removeNode() {
	cout << "Введите паспорт: ";
	string pasId = Check::inputPas();
	cout << "Введите номер карты: ";
	string cardId = Check::inputIdCard();
	nodeSkipList* temp = root;
	//если root
	if (root->card->id == cardId && root->client->passportId == pasId) {
		if (root->next) {
			nodeSkipList* temp = root;
			root = root->next;
			temp->card->availability = true;
			temp->client->countCards--;
			length--;
			delete temp;
		}
		else {
			root->card->availability = true;
			root->client->countCards--;
			length--;
			root = NULL;
		}
	}
	else {
		//если не рут, то ищем пункт, следующий от которого подходит
		if (root->title == cardId[0]) {
			while (true) {
				if (temp->next == NULL) {
					cout << "error";
					return;
				}
				if (temp->next->card->id == cardId && temp->next->client->passportId == pasId) {
					nodeSkipList* temp2 = new nodeSkipList();
					temp2 = temp->next;
					temp->next = temp2->next;
					temp2->card->availability = true;
					temp2->client->countCards--;
					length--;
					delete temp2;
					break;
				}
			}
		}
		else {
			while (true) {
				if (temp->nextSkip == NULL) {
					cout << "error";
					return;
				}

				if (temp->nextSkip->card->id[0] == cardId[0]) {
					break;
				}
				temp = temp->nextSkip;
			}
			//если следующий пункт нам и нужен
			if (temp->nextSkip->card->id == cardId && temp->nextSkip->client->passportId == pasId) {
				nodeSkipList* temp2 = new nodeSkipList();
				temp2 = temp->nextSkip;
				temp->nextSkip = temp2->nextSkip;
				while (temp->next != temp2) {
					temp = temp->next;
				}
				temp->next = temp2->next;
				temp2->card->availability = true;
				temp2->client->countCards--;
				length--;
				delete temp2;
			}
			//если не пункт, то идем от него дальше по классике
			else {
				temp = temp->nextSkip;
				while (true) {
					if (temp->next = NULL) {
						cout << "error";
						return;
					}
					if (temp->next->card->id == cardId && temp->next->client->passportId == pasId) {
						nodeSkipList* temp2 = new nodeSkipList();
						temp2 = temp->next;
						temp->next = temp2->next;
						temp2->card->availability = true;
						temp2->client->countCards--;
						length--;
						delete temp2;
					}
				}
			}
		}
	}
}

int SkipList::findByPassport() {
	int num = 0;
	cout << "Введите номер паспорта";
	string pasId = Check::inputPas();
	nodeSkipList* temp = root;
	while (temp->title != pasId[0]) {
		if (temp->nextSkip == NULL) {
			cout << "error";
			return 0;
		}
		else {
			temp = temp->nextSkip;
		}
	}
	while (temp != NULL) {
		if (pasId[0] != temp->client->passportId[0]) {
			break;
		}
		else {
			if (temp->client->passportId == pasId) {
				temp->card->viewCard();
			}
		}
		temp = temp->next;
	}
	return num;
}

bool SkipList::findByCard() {
	bool num = false;
	cout << "Введите номер карты";
	string cardId = Check::inputIdCard();
	nodeSkipList* temp = root;
	while (temp != NULL) {
			if (temp->card->id == cardId) {
				temp->client->viewClient();
				num = true;
				break;
			}
		temp = temp->next;
	}
	return num;
}

int SkipList::findByPassport(string pasId) {
	int num = 0;
	nodeSkipList* temp = root;
	while (temp->title != pasId[0]) {
		if (temp->nextSkip == NULL) {
			cout << "error";
			return 0;
		}
		else {
			temp = temp->nextSkip;
		}
	}
	while (temp != NULL) {
		if (pasId[0] != temp->client->passportId[0]) {
			break;
		}
		else {
			if (temp->client->passportId == pasId) {
				temp->card->viewCard();
			}
		}
		temp = temp->next;
	}
	return num;
}

bool SkipList::findByCard(string cardId) {
	bool num = false;
	nodeSkipList* temp = root;
	while (temp != NULL) {
		if (temp->card->id == cardId) {
			temp->client->viewClient();
			num = true;
			break;
		}
		temp = temp->next;
	}

	return num;

}

nodeSkipList* SkipList::quicksort(nodeSkipList* start, int len) {
	nodeSkipList* curr_node;
	nodeSkipList* left = nullptr;
	nodeSkipList* left_tail = nullptr;
	nodeSkipList* right = nullptr;
	nodeSkipList* right_tail = nullptr;
	nodeSkipList* next_node;
	int left_len = 0;
	int right_len = 0;

	static int j = 0;
	if (len <= 1) {
		return start;
	}
	curr_node = start->next;
	if (len == 2) {
		if (curr_node->card->getIdHowDouble() < start->card->getIdHowDouble()) {
			curr_node->next = start;
			start->next = nullptr;
			start = curr_node;
		}
		return start;
	}
	next_node = start->next;
	start->next = nullptr;

	while (next_node) {
		curr_node = next_node;
		next_node = curr_node->next;
		if (curr_node->card->getIdHowDouble() < start->card->getIdHowDouble()) {
			if (!left)
				left = curr_node;
			else
				left_tail->next = curr_node;
			left_tail = curr_node;
			left_tail->next = nullptr;
			left_len++;
		}
		else {
			if (!right)
				right = curr_node;
			else
				right_tail->next = curr_node;
			right_tail = curr_node;
			right_tail->next = nullptr;
			right_len++;
		}
	}
	left = quicksort(left, left_len);
	right = quicksort(right, right_len);
	nodeSkipList* temp;
	if (left) {
		temp = left;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = start;
		root = left;
	}
	else {
		root = start;
	}
	start->next = right;
	return root;
}


void SkipList::sort() {
	root = quicksort(root, length);
	nodeSkipList* temp = root;

	while (temp != NULL) {
		temp->title = -1;
		temp->nextSkip = NULL;
		temp = temp->next;
	}

	temp = root;
	nodeSkipList* temp2 = root;

	temp->title = temp->card->id[0];
	while (temp2 != NULL) {
		if (temp2->card->id[0] != temp->title) {
			temp->nextSkip = temp2;
			temp2->title = temp2->card->id[0];
			temp = temp2;
		}
		temp2 = temp2->next;
	}

}