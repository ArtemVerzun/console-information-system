#include "HashTable.h"
#include "Check.h"
using namespace std;

bool HashTable::isFull()
{

    // if hash size reaches maximum size
    return (curr_size == TABLE_SIZE);
}

// function to calculate first hash
int HashTable::hash1(string key)
{
    int k_int;

    k_int = (int)key[0] + (int)key[1] + (int)key[2] + (int)key[4] + (int)key[5] + (int)key[6] + (int)key[7] + (int)key[8] + (int)key[9] + (int)key[10];
    k_int = k_int % TABLE_SIZE;

    return k_int;
}

// function to calculate second hash
int HashTable::hash2(string key)
{
    int k_int;

    k_int = (int)key[0] + (int)key[1] + (int)key[2] + (int)key[4] + (int)key[5] + (int)key[6] + (int)key[7] + (int)key[8] + (int)key[9] + (int)key[10];

    return (PRIME - (k_int % PRIME));
}

HashTable::HashTable()
{
    curr_size = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = new Card;
        hashTable[i]->id = "empty";
    }
}

// function to insert key into hash table
void HashTable::insertHash()
{
    Card* card = new Card;
    card->createCard();
    string key = card->id;
    // if hash table is full
    if (isFull()) {
        cout << "База данных переполнена" << endl;
        return;
    }


    // get index from first hash
    int index = hash1(key);

    // if collision occurs
    if (hashTable[index]->id != "empty" && hashTable[index]->id != "del") {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1) {
            // get newIndex
            int newIndex = (index + i * index2) % TABLE_SIZE;

            // if no collision occurs, store
            // the key
            if (hashTable[newIndex]->id == "empty" || hashTable[newIndex]->id == "del") {
                hashTable[newIndex] = card;
                break;
            }
            i++;
        }
    }

    // if no collision occurs
    else
        hashTable[index] = card;
    curr_size++;

}

void HashTable::insertHash(Card* card)
{

    string key = card->id;
    // if hash table is full
    if (isFull()) {
        cout << "База данных переполнена" << endl;
        return;
    }


    // get index from first hash
    int index = hash1(key);

    // if collision occurs
    if (hashTable[index]->id != "empty" && hashTable[index]->id != "del") {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1) {
            // get newIndex
            int newIndex = (index + i * index2) % TABLE_SIZE;

            // if no collision occurs, store
            // the key
            if (hashTable[newIndex]->id == "empty" || hashTable[newIndex]->id == "del") {
                hashTable[newIndex] = card;
                break;
            }
            i++;
        }
    }

    // if no collision occurs
    else
        hashTable[index] = card;
    curr_size++;

}
// function to search key in hash table
Card* HashTable::searchId()
{
    string key;
    cout << "Введите id: ";
    key = Check::inputIdCard();
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    if (hashTable[index1]->id != key) {
        while (hashTable[(index1 + i * index2) % TABLE_SIZE]->id != key) {
            if (hashTable[(index1 + i * index2) % TABLE_SIZE]->id == "empty") {
                cout << key << " Не существует" << endl;
                return NULL;
            }
            i++;
        }
        //cout << key << " found" << endl;
        hashTable[(index1 + i * index2) % TABLE_SIZE]->viewCard();
        return hashTable[(index1 + i * index2) % TABLE_SIZE];
    }
    else {
        //cout << key << " found" << endl;
        hashTable[index1]->viewCard();
        return hashTable[index1];
    }
    
}

// function to display the hash table
void HashTable::displayHash()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i]->id != "empty")
            cout << i << " --> "
            << hashTable[i]->id << endl;
        else
            cout << i << endl;
    }
}

void HashTable::searchTariff() {
    cout << "Введите искомый тариф:";
    string tariff;
    tariff = Check::inputText();
    cout << "Список карт с выбранным тарифом" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i]->id != "empty" && hashTable[i]->id != "del") {
            if (hashTable[i]->tariff == tariff) {
                hashTable[i]->viewCard();
           }
        }
        else {

        }
    }
}

void HashTable::clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete(hashTable[i]);
        hashTable[i] = new Card();
        hashTable[i]->id = "empty";
        curr_size = 0;
    }
}

void HashTable::remove() {
    string key;
    cout << "id";
    key = Check::inputIdCard();
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    while (hashTable[(index1 + i * index2) % TABLE_SIZE]->id != key) {
        if (hashTable[(index1 + i * index2) % TABLE_SIZE]->id == "empty" || hashTable[(index1 + i * index2) % TABLE_SIZE]->id == "del") {
            cout << key << " does not exist" << endl;
            return;
        }
        i++;
    }
    if (hashTable[(index1 + i * index2) % TABLE_SIZE]->availability) {
        cout << key << " delete" << endl;
        delete(hashTable[(index1 + i * index2) % TABLE_SIZE]);
        hashTable[(index1 + i * index2) % TABLE_SIZE] = new Card();
        hashTable[(index1 + i * index2) % TABLE_SIZE]->id = "del";
        curr_size--;
    }
    else {
        cout << "Карта выдана, нельзя удалить";
    }
    

}
