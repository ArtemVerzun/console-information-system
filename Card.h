#ifndef CARD_HEADER
#define CARD_HEADER
#include <string>
#include <iostream>
//Ц Ќомер SIM - карты Ц строка формата ЂNNN - NNNNNNNї, г д е   N Ццифра; Ц “ариф Ц строка; Ц √од выпуска Ц целое; Ц ѕризнак наличи€ Ц логическое.
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
