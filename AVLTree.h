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

    int max(int a, int b) { return (a > b ? a : b); } //��������
    int GetHeight(NodeClient* temp) { return ((temp == nullptr) ? -1 : temp->height); } //�������� ������
    int BalanceFactor(NodeClient* temp) { return (GetHeight(temp->right) - GetHeight(temp->left)); } //������ ������������
    //������� ��� ��������� � ������������:
    void HeightBalance(NodeClient* temp); //���������� ���������� ������
    void TreeFix(NodeClient* temp);//����� ���������
    void Rebalancer(NodeClient* temp); //�������������� ������
    void LeftRotate(NodeClient* x);//����� �������
    void RightRotate(NodeClient* x);//������ �������
    void RemoveNode(NodeClient* Parent, NodeClient* curr, double stuff); //�������� ��������
    void Clear(NodeClient* temp); //������� ��������

public:
    AVLTree() : root(nullptr) {}
    NodeClient* GetRoot() { return root; } //�������� ������
    void Insert(); //�������� �������
    void Insert(Client* stuff); //�������� �������
    void Remove(); //�������� ������� �� id
    void Clear(); //������� ������
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
