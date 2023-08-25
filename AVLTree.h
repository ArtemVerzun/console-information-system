#ifndef AVLTREE_HEADER
#define AVLTREE_HEADER
#ifndef NODECLIENT_HEADER
#define NODECLIENT_HEADER
#include "Client.h"
#include <string>


struct NodeClient{
    Client* client;
    NodeClient* left = nullptr;
    NodeClient* right = nullptr;
    NodeClient* parent = nullptr;
    int height;
};

class AVLTree{
private:
    int tabs = 0;
    NodeClient* root;

    int max(int a, int b) { return (a > b ? a : b); } //максимум
    int GetHeight(NodeClient* temp) { return ((temp == nullptr) ? -1 : temp->height); } //получить высоту
    int BalanceFactor(NodeClient* temp) { return (GetHeight(temp->right) - GetHeight(temp->left)); } //фактор балансировки
    //функции для поворотов и балансировки:
    void HeightBalance(NodeClient* temp); //обновление параметров высоты
    void TreeFix(NodeClient* temp);//вызов поворотов
    void Rebalancer(NodeClient* temp); //ребалансировка дерева
    void LeftRotate(NodeClient* x);//левый поворот
    void RightRotate(NodeClient* x);//правый поворот
    void RemoveNode(NodeClient* Parent, NodeClient* curr, double stuff); //удаление рекурсия
    void Clear(NodeClient* temp); //очистка рекурсия

public:
    AVLTree() : root(nullptr) {}
    NodeClient* GetRoot() { return root; } //получить корень
    void Insert(); //добавить клиента
    void Insert(Client* stuff); //добавить клиента
    void Remove(); //удаление клиента по id
    void Clear(); //очистка дерева
    Client* TreeSearch(double stuff);
    void outputTree(NodeClient* t, int u);
    void directTraversal(NodeClient* t);
    Client* findIdSys(NodeClient* t, double stuff, Client* find);
    Client* findId();
    bool directSearch(string text, string word);
    void findFullNameSys(NodeClient* t, string word);
    void findFullName();
    double fromStringToDouble(string text);


};
#endif
#endif
