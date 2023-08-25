#ifndef HASHTABLE_HEADER
#define HASHTABLE_HEADER

// Hash table size
#define TABLE_SIZE 5

// Used in second hash function.
#define PRIME 3

#include "string"
#include "Card.h"
using namespace std;
class HashTable {
    Card* hashTable[TABLE_SIZE];
    int curr_size;

public:
    bool isFull();

    int hash1(string key);

    int hash2(string key);

    HashTable();

    void insertHash();

    void insertHash(Card* card);

    Card* searchId();

    void searchTariff();

    void displayHash();

    void clear();

    void remove();

};

#endif