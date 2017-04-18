//Name:
//Date:
//program:
//Description:

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node {
private:
    //Node *left, *right;
    //std::string key;
    //int data;

public:
    Node(std::string key);
    Node *left, *right;
    int data;
    std::string key;

};

class BinarySearchTree{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void setNode(string key, int data);
    void print();
    void minNode();
    void maxNode();
    void save_file(string name);
    void deleteNode(int data);
    //void deleteHelper(Node* &current, int data);

private:
    Node *root;
    void deleteHelper(Node* &current, int value);
    void insertHelper(Node *current, string key, int value);
    void printHelper(Node *current);
    void destructorHelper(Node* current);
    void fileprintHelper(Node *current, ofstream& out);
};
