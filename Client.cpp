#include "Client.h"
#include "Check.h"
#include <iostream>

void Client::createClient() {
	cout << "Введите паспорт в формате ****-******: ";
	this->passportId = Check::inputPas();
	cout << "Введите ФИО: ";
	this->fullName = Check::inputText();
	cout << "Введите место и кем выдано: ";
	this->passportInfo = Check::inputText();
	cout << "Введите адрес: ";
	this->address = Check::inputText();
	cout << "Введите год рождения: ";
	this->yearOfBirth = Check::inputYear();
}

void Client::createClient(string passportId, string passportInfo, string fullName, string address, int yearOfBirth) {
	this->passportId = passportId;
	this->passportInfo = passportInfo;
	this->fullName = fullName;
	this->address = address;
	this->yearOfBirth = yearOfBirth;
}

void Client::viewClient() {
	cout << "Номер паспорта: " << this->passportId << endl;
	cout << "ФИО: " << this->fullName << endl;
	cout << "Кол-во карт: " << this->countCards << endl;
	
}


double Client::getPasIdhowDouble() {
	double res;
	string temp1 = "";
	temp1 = passportId.substr(0, 4);
	res = stod(temp1);
	string temp2 = "";
	temp2 = passportId.substr(5, 6);
	res += (stod(temp2) / 1000000);
	return res;
}
