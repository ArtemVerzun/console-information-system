#include "Check.h"
#include <iostream>
#include <string>
#include "AVLTree.h"
#include <Windows.h>
#include "HashTable.h"
#include "SkipList.h"

using namespace std;

AVLTree* tree;
HashTable* table;
SkipList* list;

void clientMenu() {
	system("cls");
	cout << "________________________________________________________" << endl;
	cout << "|               ���������� ���������                   |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. ����������� ������ �������                        |" << endl;
	cout << "| 2. ������ ������� � ������������                     |" << endl;
	cout << "| 3. �������� ������                                   |" << endl;
	cout << "| 4. �������� ���� ������������������ ��������         |" << endl;
	cout << "| 5. ������� ������ � ��������                         |" << endl;
	cout << "| 6. ����� ������� �� ������ ��������                  |" << endl;
	cout << "| 7. ����� ������� �� ���                              |" << endl;
	cout << "| ��� �������� ����� ������� ����� ������ �����        |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIclientMenu() {
	int info = 0;
	bool next = true;
	clientMenu();
	while (next) {
		cout << "�����?: ";
		info = Check::inputOnlyNumber();
		clientMenu();
		switch (info)
		{
		case 1: tree->Insert(); break;
		case 2: tree->Remove(); break;
		case 3: tree->outputTree(tree->GetRoot(), 0); break;
		case 4: tree->directTraversal(tree->GetRoot()); break;
		case 5: tree->Clear(); break;
		case 6: tree->findId(); break;
		case 7: tree->findFullName(); break;
		default: next = false; break;
		}
	}
}

void simMenu() {
	system("cls");
	cout << "________________________________________________________" << endl;
	cout << "|               ���������� SIM-�������                  |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. ���������� ����� �����                             |" << endl;
	cout << "| 2. �������� �������� � �����                          |" << endl;
	cout << "| 3. �������� ���� ��������� ����                       |" << endl;
	cout << "| 4. ������� ������ � ������                            |" << endl;
	cout << "| 5. ����� ����� �� ������                              |" << endl;
	cout << "| 6. ����� ����� �� ������                              |" << endl;
	cout << "| ��� �������� ����� ������� ����� ������ �����        |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIsimMenu() {
	int info = 0;
	bool next = true;
	simMenu();
	while (next) {
		cout << "�����?: ";
		info = Check::inputOnlyNumber();
		simMenu();
		switch (info)
		{
		case 1: table->insertHash(); break;
		case 2: table->remove(); break;
		case 3: table->displayHash(); break;
		case 4: table->clear(); break;
		case 5: table->searchId(); break;
		case 6: table->searchTariff(); break;
		default: next = false; break;
		}
	}
}

void receptionMenu() {
	system("cls");
	cout << "________________________________________________________" << endl;
	cout << "|               ������/����� ����                       |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. ������ �����                                       |" << endl;
	cout << "| 2. ������� �����                                      |" << endl;
	cout << "| 3. �������� ���� �������� ����                        |" << endl;
	cout << "| 4. ����������                                         |" << endl;
	cout << "| ��� �������� ����� ������� ����� ������ �����         |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIreceptionMenu() {
	int info = 0; 
	bool next = true;
	receptionMenu();
	while (next) {
		cout << "�����?: ";
		info = Check::inputOnlyNumber();
		receptionMenu();
		switch (info)
		{
		case 1: list->addNode(); break;
		case 2: list->removeNode(); break;
		case 3: list->viewList(); break;
		case 4: list->sort(); break;
		default: next = false; break;
		}
	}
}


void testData() {
	Client* client1 = new Client();
	client1->createClient("1111-111111", "�����", "������ ���� ��������", "������", 1974);
	tree->Insert(client1);
	Client* client2 = new Client();
	client2->createClient("2222-222222", "�����", "�������� ������� ���������", "��������������", 1981);
	tree->Insert(client2);
	Client* client3 = new Client();
	client3->createClient("3333-333333", "�����", "�������� ������� ����������", "������������", 2000);
	tree->Insert(client3);

	Card* card1 = new Card();
	card1->createCard("111-1111111", "�����", 2007);
	table->insertHash(card1);
	Card* card2 = new Card();
	card2->createCard("222-2222222", "�����", 2020);
	table->insertHash(card2);
	Card* card3 = new Card();
	card3->createCard("333-3333333", "�����bot", 2015);
	table->insertHash(card3);

	list->addNode(client1, card1);
	list->addNode(client1, card3);
	list->addNode(client2, card2);
}


void mainMenu() {
	system("cls");
	cout << "________________________________________________________" << endl;
	cout << "|                  ����� ����                          |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. ������� � ���������� ���������                    |" << endl;
	cout << "| 2. ������� � ���������� SIM-�������                  |" << endl;
	cout << "| 3. ������� � ������/������ ����                      |" << endl;
	cout << "| 4. ��������� �������� ������                         |" << endl;
	cout << "________________________________________________________" << endl;
}


void UImainMenu() {
	int info = 0;
	while (true) {
		mainMenu();
		info = Check::inputOnlyNumber();
		switch (info)
		{
		case 1: UIclientMenu(); break;
		case 2: UIsimMenu(); break;
		case 3: UIreceptionMenu(); break;
		case 4: testData(); break;
		default: break;
		}
	}
}


int main() {
	//setlocale(LC_ALL, "Rus");
	system("chcp1521");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	table = new HashTable();
	tree = new AVLTree();
	list = new SkipList(tree, table);

	UImainMenu();


	return 0;
}