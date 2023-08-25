#ifndef CHECK_HEADER
#define CHECK_HEADER

#include <string>
#include <iostream>

class Check {
public:
	static long int inputOnlyNumber();
	static int inputOnlyNumberInRange(int left, int right);
	static double inputOnlyDouble();
	static std::string inputText();
	static std::string inputText(int length);
	static std::string inputIdCard();
	static double inputPasId();
	static std::string inputPas();
	static int inputYear();
};

#endif 
