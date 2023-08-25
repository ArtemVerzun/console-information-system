#ifndef CLIENT_HEADER
#define CLIENT_HEADER

#include <string>
#include <iostream>
using namespace std;

class Client {
public:
	string passportId;
	string passportInfo;
	string fullName;
	string address;
	int yearOfBirth;
	int countCards = 0;

	void createClient(string passportId, string passportInfo, string fullName, string address, int yearOfBirth);
	void createClient();
	void editClient();
	void viewClient();
	double getPasIdhowDouble();
};
#endif