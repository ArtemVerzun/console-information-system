#ifndef CARD_HEADER
#define CARD_HEADER
#include <string>
#include <iostream>
//� ����� SIM - ����� � ������ ������� �NNN - NNNNNNN�, � � �   N ������; � ����� � ������; � ��� ������� � �����; � ������� ������� � ����������.
class Card {
public:
	std::string id;
	std::string tariff;
	int yearOfIssue;
	bool availability = true;

	void createCard();
	void createCard(std::string id, std::string tariff, int year);
	void editCard();
	void viewCard();
	double getIdHowDouble();
};
#endif
