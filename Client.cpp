#include "Client.h"
#include "Check.h"
#include <iostream>

void Client::createClient() {
	cout << "������� ������� � ������� ****-******: ";
	this->passportId = Check::inputPas();
	cout << "������� ���: ";
	this->fullName = Check::inputText();
	cout << "������� ����� � ��� ������: ";
	this->passportInfo = Check::inputText();
	cout << "������� �����: ";
	this->address = Check::inputText();
	cout << "������� ��� ��������: ";
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
	cout << "����� ��������: " << this->passportId << endl;
	cout << "���: " << this->fullName << endl;
	cout << "���-�� ����: " << this->countCards << endl;
	
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
