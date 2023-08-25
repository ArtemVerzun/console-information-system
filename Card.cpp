#include "Card.h"
#include "Check.h"
void Card::createCard() {
	std::cout << "������ ����� ����� � ������� ***-*******: ";
	this->id = Check::inputIdCard();
	std::cout << "������ ����� �����: ";
	this->tariff = Check::inputText();
	std::cout << "������� ���� �������";
	this->yearOfIssue = Check::inputYear();
}

void Card::createCard(std::string id, std::string tariff, int year) {
	this->id = id;
	this->tariff = tariff;
	this->yearOfIssue = year;
	this->availability = true;
}

void Card::viewCard() {
	std::cout << "����� �����: " << this->id << std::endl;
	std::cout << "����� �����: " << this->tariff << std::endl;
	if (this->availability) {
		std::cout << "��������";
	}
	else {
		std::cout << "����������";
	}
	std::cout << std::endl;
}

double Card::getIdHowDouble() {
	double res;
	std::string temp1 = "";
	temp1 = id.substr(0, 3);
	res = stod(temp1);
	std::string temp2 = "";
	temp2 = id.substr(4, 7);
	res += (stod(temp2) / 10000000);
	return res;
}