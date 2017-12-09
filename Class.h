//Name: Nicholas Reid
//Date: 12/8/2017
//Program: Class.h
//Description: header file for the program

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node {
private:
    Node *left, *right;
    std::string key;
    int data;

public:
    Node(string key);
    void setData(int num);
    int Data();
    void setKey(string key);
    string Key();
    void setLeft(Node* current);
    Node* Left(){
        return left;
    };
    void setRight(Node* current);
    Node* Right(){
        return right;
    };
};

class associativeArray{
public:
    associativeArray();
    ~associativeArray();
    void setNode(string key, int data);
    void find(string key);
    void print();
    void minNode();
    void maxNode();
    void save_file(string name);
    void deleteNode(string key);
    //operator [];

private:
    Node *root;
    void deleteHelper(Node* parent, string key);
    void insertHelper(Node *current, string key, int value);
    void printHelper(Node *current);
    void destructorHelper(Node* current);
    void saveHelper(Node *current, ofstream& out);
    void findHelper(Node* current, string key);
};

#endif
