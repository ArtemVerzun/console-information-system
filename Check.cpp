#include "Check.h"
long int Check::inputOnlyNumber() {
    long int N;
    for (;;) {
        if ((std::cin >> N).good()) return N;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "�������� ����, ���������.\n";
        }
        std::cin.ignore();
    }
    return N;
}

int Check::inputOnlyNumberInRange(int left, int right) {
    int N;
    for (;;) {
        if ((std::cin >> N).good() && (left <= N) && (N < right)) return N;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "�������� ����, ���������.\n";
        }
        else {
            std::cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
        }
        std::cin.ignore();
    }
}

double Check::inputOnlyDouble() {
    double N;
    while (!(std::cin >> N) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "�������� ����, ���������.\n" << std::endl;
    }
    return N;
}

std::string Check::inputText() {
    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.ignore();
    }
    std::string text;
    std::getline(std::cin, text);
    return text;
}

std::string Check::inputText(int length) {
    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.ignore();
    }
    std::string text;
    while (true) {
        std::getline(std::cin, text);
        if (text.length() != length) {
            std::cout << "����� ������ �������� �� " << length << " ��������, ��������� ����"<<std::endl;
        }
        else {
            break;
        }
    }
    return text;
}

std::string Check::inputIdCard() {
    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.ignore();
    }
    std::string text;
    while (true) {
        std::getline(std::cin, text);
        if (text.length() != 11) {
            std::cout << "����� ������ �������� �� 11 ��������, ��������� ����" << std::endl;
        }
        else {
            if (text[3] != '-') {
                std::cout << "������������ ����, ���������" << std::endl;
            }
            else {
                break;
            }
        }
    }
    return text;
}

int Check::inputYear() {
    int N;
    for (;;) {
        if ((std::cin >> N).good()) {
            int temp = N;
            int n = 0;
            while ((temp /= 10) > 0) n++;
            if (n == 4) {
                return N;
            }      
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "�������� ����, ���������.\n";
        }
        std::cin.ignore();
    }
    return N;
}

double Check::inputPasId(){
    std::string text = inputPas();
    double res;
    std::string temp1 = "";
    temp1=text.substr(0,4);
    res = stod(temp1);
    std::string temp2 = "";
    temp2 = text.substr(5, 6);
    res += (stod(temp2) / 1000000);
    return res;
}

std::string Check::inputPas() {
    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.ignore();
    }
    std::string text;
    while (true) {
        std::getline(std::cin, text);
        if (text.length() != 11) {
            std::cout << "����� ������ �������� �� 11 ��������, ��������� ����" << std::endl;
        }
        else {
            if (text[4] != '-') {
                std::cout << "������������ ����, ���������" << std::endl;
            }
            else {
                break;
            }
        }
    }
    return text;
}