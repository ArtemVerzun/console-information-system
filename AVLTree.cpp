#include "AVLTree.h"
#include "Check.h"
#include <iomanip>

using namespace std;
void AVLTree::HeightBalance(NodeClient* temp) {

	int l = -1, r = -1;
	if (temp->left) { l = temp->left->height; }
	if (temp->right) { r = temp->right->height; }
	temp->height = max(l, r) + 1;
}

void AVLTree::TreeFix(NodeClient* temp) {
	if (BalanceFactor(temp) == 2) {
		if (BalanceFactor(temp->right) < 0) { RightRotate(temp->right); }
		LeftRotate(temp);
		HeightBalance(temp);
	}
	else if (BalanceFactor(temp) == -2) {
		if (BalanceFactor(temp->left) > 0) { LeftRotate(temp->left); }
		RightRotate(temp);
		HeightBalance(temp);
	}
}

void AVLTree::Rebalancer(NodeClient* temp) {
	if (temp == root) { TreeFix(root); }
	else {
		while (temp != nullptr) {
			HeightBalance(temp);
			temp = temp->parent;
			if (temp) { TreeFix(temp); }
		}
	}
}

void AVLTree::LeftRotate(NodeClient* x) {
	NodeClient* nw_node = new NodeClient();
	if (x->right->left) { nw_node->right = x->right->left; }
	nw_node->left = x->left;
	nw_node->client = x->client;
	x->client = x->right->client;

	x->left = nw_node;
	if (nw_node->left) { nw_node->left->parent = nw_node; }
	if (nw_node->right) { nw_node->right->parent = nw_node; }
	nw_node->parent = x;

	if (x->right->right) { x->right = x->right->right; }
	else { x->right = nullptr; }

	if (x->right) { x->right->parent = x; }

	HeightBalance(x->left);
	if (x->right) { HeightBalance(x->right); }
	HeightBalance(x);
}

void AVLTree::RightRotate(NodeClient* x) {
	NodeClient* nw_node = new NodeClient();
	if (x->left->right) { nw_node->left = x->left->right; }
	nw_node->right = x->right;
	nw_node->client = x->client;
	x->client = x->left->client;

	x->right = nw_node;
	if (nw_node->left) { nw_node->left->parent = nw_node; }
	if (nw_node->right) { nw_node->right->parent = nw_node; }
	nw_node->parent = x;

	if (x->left->left) { x->left = x->left->left; }
	else { x->left = nullptr; }

	if (x->left) { x->left->parent = x; }

	HeightBalance(x->right);
	if (x->left) { HeightBalance(x->left); }
	HeightBalance(x);
}

void AVLTree::RemoveNode(NodeClient* Parent, NodeClient* curr, double stuff) {

		if (curr == nullptr) { return; }
		if (curr->client->getPasIdhowDouble() == stuff) {
			//CASE -- 1
			if (curr->left == nullptr && curr->right == nullptr) {
				if (Parent->client->getPasIdhowDouble() == curr->client->getPasIdhowDouble()) { root = nullptr; }
				else if (Parent->right == curr) { Parent->right = nullptr; }
				else { Parent->left = nullptr; }
				Rebalancer(Parent);
			}
			//CASE -- 2
			else if (curr->left != nullptr && curr->right == nullptr) {
				Client* sp = curr->client;
				curr->client = curr->left->client;
				curr->left->client = sp;
				RemoveNode(curr, curr->left, stuff);
			}
			else if (curr->left == nullptr && curr->right != nullptr) {
				Client* sp = curr->client;
				curr->client = curr->right->client;
				curr->right->client = sp;
				RemoveNode(curr, curr->right, stuff);
			}
			//CASE -- 3
			else {
				NodeClient* temp = curr->right;
				int flag = 0;
				while (temp->left) { flag = 1; Parent = temp; temp = temp->left; }
				if (!flag) { Parent = curr; }
				Client* sp = curr->client;
				curr->client = temp->client;
				temp->client = sp;
				RemoveNode(Parent, temp, temp->client->getPasIdhowDouble());
			}
		}
}

void AVLTree::Clear(NodeClient* temp) {
	if (temp != nullptr) {
		Clear(temp->right);
		Clear(temp->left);
		delete temp;

	}
	temp = nullptr;
}

void AVLTree::Insert() {
	Client* stuff = new Client();
	stuff->createClient();
	if (TreeSearch(stuff->getPasIdhowDouble()) == nullptr) {
		if (root == nullptr) {
			root = new NodeClient();
			root->client = stuff;
			// cout << "Элемент вставлен.\n";
			root->height = 0;
			root->parent = nullptr;
		}
		else {
			auto linker = GetRoot();
			NodeClient* newnode = new NodeClient();
			newnode->client = stuff;
			while (linker != nullptr) {
				if (linker->client->passportId > stuff->passportId) {
					if (linker->left == nullptr) {
						linker->left = newnode;
						newnode->height = 0;
						newnode->parent = linker;


						break;
					}
					else { linker = linker->left; }
				}
				else {
					if (linker->right == nullptr) {
						linker->right = newnode;
						newnode->height = 0;
						newnode->parent = linker;

						break;
					}
					else { linker = linker->right; }
				}
			}
			Rebalancer(newnode);
		}
		tabs++;
	}
	else {

	}
}

void AVLTree::Insert(Client* stuff) {

	if (TreeSearch(stuff->getPasIdhowDouble()) == nullptr) {
		if (root == nullptr) {
			root = new NodeClient();
			root->client = stuff;
			// cout << "Элемент вставлен.\n";
			root->height = 0;
			root->parent = nullptr;
		}
		else {
			auto linker = GetRoot();
			NodeClient* newnode = new NodeClient();
			newnode->client = stuff;
			while (linker != nullptr) {
				if (linker->client->passportId > stuff->passportId) {
					if (linker->left == nullptr) {
						linker->left = newnode;
						newnode->height = 0;
						newnode->parent = linker;


						break;
					}
					else { linker = linker->left; }
				}
				else {
					if (linker->right == nullptr) {
						linker->right = newnode;
						newnode->height = 0;
						newnode->parent = linker;

						break;
					}
					else { linker = linker->right; }
				}
			}
			Rebalancer(newnode);
		}
		tabs++;
	}
	else {

	}
}

void AVLTree::Remove() {
	cout << "Введите номер паспорта: ";
	double idClient = Check::inputPasId();
	auto temp = root;
	auto Parent = temp;
	bool flag = false;
	if (temp == nullptr) { RemoveNode(nullptr, nullptr, idClient); }

	while (temp) {
		if (idClient == temp->client->getPasIdhowDouble()) { 
			if (temp->client->countCards > 0) {
				cout << "У пользователя есть выданные карты" <<endl;
				return;
			}
			else {
				flag = true;
				RemoveNode(Parent, temp, idClient);
				break;
			}
		}
		else if (idClient < temp->client->getPasIdhowDouble()) { Parent = temp; temp = temp->left; }
		else { Parent = temp; temp = temp->right; }
	}

	if (!flag) {
		cout << "Элемент недоступен\n";
	}
	else {
		cout << "Элемент удален.\n";
		tabs--;
	}
}

Client* AVLTree::TreeSearch(double stuff) {
	auto temp = GetRoot();
	if (temp == nullptr) { return nullptr; }

	while (temp) {
		if (stuff == temp->client->getPasIdhowDouble()) { return temp->client; }
		else if (stuff <= temp->client->getPasIdhowDouble()) { temp = temp->left; }
		else { temp = temp->right; }
	}
	return nullptr;
}

void AVLTree::Clear() {
	Clear(root);
	root = nullptr;
}

void AVLTree::outputTree(NodeClient* t, int u) {
	if (t != NULL) {
		if (t->right) {
			outputTree(t->right, u + 4);
		}
		if (u) {
			std::cout << setw(u) << ' ';
		}
		if (t->right) std::cout << " /\n" << setw(u) << ' ';
		cout << t->client->passportId << "\n ";
		if (t->left) {
			std::cout << setw(u) << ' ' << " \\\n";
			outputTree(t->left, u + 4);
		}
	}
}

void AVLTree::directTraversal(NodeClient* t) {
	if (t == NULL) return;
	cout << t->client->passportId << endl; //И показываем элемент
	directTraversal(t->left);//С помощью рекурсивного посещаем левое поддерево
	directTraversal(t->right); //С помощью рекурсии посещаем правое поддерево
}

Client* AVLTree::findIdSys(NodeClient* t, double stuff, Client* find) {
	if (t == NULL) return find;
	if (find != NULL) return find;
	if (t->client->getPasIdhowDouble() == stuff) {
		t->client->viewClient();
		find = t->client;
		return find;
	}
	find = findIdSys(t->left, stuff, find);//С помощью рекурсивного посещаем левое поддерево
	find = findIdSys(t->right, stuff, find); //С помощью рекурсии посещаем правое поддерево
}

Client* AVLTree::findId() {
	Client* find = NULL;
	cout << "Введите номер паспорта";
	double stuff = Check::inputPasId();
	find = findIdSys(GetRoot(), stuff, find);
	return find;
}

bool AVLTree::directSearch(string text, string word) {
	int count;
	int lengthText = text.length();
	int lenghtWord = word.length();
	for (int i = 0; i < lengthText; i++) {
		if (text[i] == word[0]) {
			count = 1;
			for (int j = 1; j < lenghtWord; j++) {
				if (text[i + j] == word[j]) {
					count++;
				}
				else {

					break;
				}
			}
			if (count == lenghtWord) {
				return true;
			}
		}
	}
	return false;
}

void AVLTree::findFullNameSys(NodeClient* t, string word) {
	if (t == NULL) return;
	if (directSearch(t->client->fullName, word)) {
		t->client->viewClient();
	}
		findFullNameSys(t->left, word);//С помощью рекурсивного посещаем левое поддерево
		findFullNameSys(t->right, word); //С помощью рекурсии посещаем правое поддерево
	
}

void AVLTree::findFullName() {
	cout << "Введите часть ФИО: ";
	string word;
	word = Check::inputText();
	findFullNameSys(GetRoot(), word);
}

