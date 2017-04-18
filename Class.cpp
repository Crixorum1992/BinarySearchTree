//Name:
//Date:
//Program:
//Description:

#include "Class.h"

Node::Node(string key){
    left=NULL;
    right=NULL;
}


BinarySearchTree::BinarySearchTree(){
    root = NULL;
};

BinarySearchTree::~BinarySearchTree(){
    destructorHelper(root);
};

void BinarySearchTree::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}

void BinarySearchTree::setNode(string key, int data){
    if(root == NULL){
        root = new Node(key);
        root->key = key;
        root->data = data;
    }
    else
        insertHelper(root, key, data);
};

void BinarySearchTree::insertHelper(Node *current, string key, int value) {
    if(value < current->data) {
    //Insert Left
        if(current->left == NULL){
            current->left = new Node(key);
            current->left->key = key;
            current->left->data = value;
        }
        else
            insertHelper(current->left, key, value);
    }
    else {
    //Insert Right
        if(current->right == NULL){
            current->right = new Node(key);
            current->right->key = key;
            current->right->data = value;
        }
        else
            insertHelper(current->right, key, value);
    }

}

void BinarySearchTree::print(){
    printHelper(root);
    cout << endl;
};

void BinarySearchTree::printHelper(Node *current) {
    // In-order traversal.
    if(current != NULL) {
        printHelper(current->left);
        cout << current->key << " ";
        printHelper(current->right);
    }
}

void BinarySearchTree::minNode(){
    Node *current;
    current = root;
    if (current != NULL){
        current = current->left;
    }
    cout<<current->key<<endl;
};

void BinarySearchTree::maxNode(){
    Node *current;
    current = root;
    if (current != NULL){
        current = current->right;
    }
    cout<<current->key<<endl;
};

void BinarySearchTree::save_file(string name){
    ofstream outfile;
    outfile.open(name.c_str());
    if (outfile.fail()){
		cout<<"cout unable to open file";
	}

	fileprintHelper(root, outfile);

	outfile.close();

};

void BinarySearchTree::fileprintHelper(Node *current, ofstream& out){
    if(current != NULL) {
        printHelper(current->left);
        out << current->key << endl;
        printHelper(current->right);
    }
};

void BinarySearchTree::deleteNode(int data){
    deleteHelper(root, data);
};

void BinarySearchTree::deleteHelper(Node* &current, int data){
    //Node doesn't exist
    if(current == NULL)
        return;
    //Go left
    else if(data < current->data)
        deleteHelper(current->left, data);
    //Go right
    else if(current->data < data)
        deleteHelper(current->right, data);
    //No children
    else {
        Node *temp;

    if(current->left == NULL) {
        temp = current->right;
        delete current;
        current = temp;
    }
    else if(current->right == NULL) {
        temp = current->left;
        delete current;
        current = temp;
    }
    //2 children
    else {
        temp = current->right;
        Node *parent = NULL;

        while(temp->left != NULL) {
            parent = temp;
            temp = temp->left;
        }

        current->data = temp->data;

        if(parent != NULL)
            deleteHelper(parent->left, parent->left->data);
        else
            deleteHelper(current->right, current->right->data);

        }//else
    }//else
};

