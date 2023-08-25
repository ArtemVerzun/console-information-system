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
	cout << "|               Управление клиентами                   |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. Регистрация нового клиента                        |" << endl;
	cout << "| 2. Снятие клиента с обслуживания                     |" << endl;
	cout << "| 3. Просмотр дерева                                   |" << endl;
	cout << "| 4. Просмотр всех зарегестрированных клиентов         |" << endl;
	cout << "| 5. Очистка данных о клиентах                         |" << endl;
	cout << "| 6. Поиск клиента по номеру паспорта                  |" << endl;
	cout << "| 7. Поиск клиента по ФИО                              |" << endl;
	cout << "| Для возврата назад введите любое другое число        |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIclientMenu() {
	int info = 0;
	bool next = true;
	clientMenu();
	while (next) {
		cout << "Далее?: ";
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
	cout << "|               Управление SIM-картами                  |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. Добавление новой карты                             |" << endl;
	cout << "| 2. Удаление сведений о карте                          |" << endl;
	cout << "| 3. Просмотр всех имеющихся карт                       |" << endl;
	cout << "| 4. Очистка данных о картах                            |" << endl;
	cout << "| 5. Поиск карты по номеру                              |" << endl;
	cout << "| 6. Поиск карты по тарифу                              |" << endl;
	cout << "| Для возврата назад введите любое другое число        |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIsimMenu() {
	int info = 0;
	bool next = true;
	simMenu();
	while (next) {
		cout << "Далее?: ";
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
	cout << "|               Выдача/прием карт                       |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. Выдать карту                                       |" << endl;
	cout << "| 2. Возврат карты                                      |" << endl;
	cout << "| 3. Просмотр всех выданных карт                        |" << endl;
	cout << "| 4. Сортировка                                         |" << endl;
	cout << "| Для возврата назад введите любое другое число         |" << endl;
	cout << "________________________________________________________" << endl;
}

void UIreceptionMenu() {
	int info = 0; 
	bool next = true;
	receptionMenu();
	while (next) {
		cout << "Далее?: ";
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
	client1->createClient("1111-111111", "место", "Иванов Иван Иванович", "Москва", 1974);
	tree->Insert(client1);
	Client* client2 = new Client();
	client2->createClient("2222-222222", "место", "Дмитриев Дмитрий Дмитрович", "Днепропетровск", 1981);
	tree->Insert(client2);
	Client* client3 = new Client();
	client3->createClient("3333-333333", "место", "Евгениев Евгений Евгеньевич", "Екатеринбург", 2000);
	tree->Insert(client3);

	Card* card1 = new Card();
	card1->createCard("111-1111111", "тариф", 2007);
	table->insertHash(card1);
	Card* card2 = new Card();
	card2->createCard("222-2222222", "тариф", 2020);
	table->insertHash(card2);
	Card* card3 = new Card();
	card3->createCard("333-3333333", "тарифbot", 2015);
	table->insertHash(card3);

	list->addNode(client1, card1);
	list->addNode(client1, card3);
	list->addNode(client2, card2);
}


void mainMenu() {
	system("cls");
	cout << "________________________________________________________" << endl;
	cout << "|                  Общее меню                          |" << endl;
	cout << "________________________________________________________" << endl;
	cout << "| 1. Перейти к управлению клиентами                    |" << endl;
	cout << "| 2. Перейти к управлению SIM-картами                  |" << endl;
	cout << "| 3. Перейти к выдаче/приему карт                      |" << endl;
	cout << "| 4. Заполнить тестовые данные                         |" << endl;
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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	table = new HashTable();
	tree = new AVLTree();
	list = new SkipList(tree, table);

	UImainMenu();


	return 0;
}