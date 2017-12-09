//Name: Nicholas Reid
//Date: 12/8/2017
//Program: Class.cpp
//Description: driver functions for program

#include "Class.h"

Node::Node(string key){
    this->key = key;
    data = 0;
    right = NULL;
    left = NULL;
}

void Node::setData(int num){
    data = num;
}

int Node::Data(){
    return data;
}

void Node::setKey(string key){
    this->key == key;
}

string Node::Key(){
    return key;
}

void Node::setLeft(Node* current){
    left = current;
}

/*Node* Left(){
    return left;
}*/

void Node::setRight(Node* current){
    right = current;
}

/*Node* Right(){
    return right;
}*/


associativeArray::associativeArray(){
    root = NULL;
};

associativeArray::~associativeArray(){
    destructorHelper(root);
};

void associativeArray::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->Left());
    destructorHelper(current->Right());
    delete current;
  }
}

void associativeArray::setNode(string key, int data){
    if(root == NULL){
        root = new Node(key);
        root->setData(data);
        //root->setKey(key);
    }
    else
        insertHelper(root, key, data);
};

void associativeArray::insertHelper(Node *current, string key, int value) {
    if(value == current->Data()){
        current->setData(value);
    }

    else if(value < current->Data()){ //Insert Left
        if(current->Left() == NULL){
            current->setLeft(new Node(key));
            current->Left()->setData(value);
            //current->Left()->setKey(key);
        }
        else
            insertHelper(current->Left(), key, value);
        }

    else if(value > current->Data()){ //Insert Right
        if(current->Right() == NULL){
            current->setRight(new Node(key));
            current->Right()->setData(value);
            //current->Right()->setKey(key);
        }
        else
            insertHelper(current->Right(), key, value);
        }

    else{
        cout << "Failed.. Returning" << endl;
        return;
    }
}

void associativeArray::find(string key){
    findHelper(root, key);
}

void associativeArray::findHelper(Node *current, string key){
    while(current != NULL){
        if(current->Key() == key)
            cout<<current->Data()<<endl;
        else if(current -> Key() < key)
            findHelper(current -> Right(), key);
        else if(current -> Key() > key)
            findHelper(current -> Left(), key);
    }
};

void associativeArray::print(){
    printHelper(root);
};

void associativeArray::printHelper(Node *current) {
    // In-order traversal.
    if(current != NULL) {
        printHelper(current->Left());
        cout << current -> Key() << " ";
        printHelper(current->Right());
    }
}

void associativeArray::minNode(){
    Node *current;
    current = root;
    if (current != NULL){
        current = current->Left();
    }
    cout<<current->Key()<<endl;
};

void associativeArray::maxNode(){
    Node *current;
    current = root;
    if (current != NULL){
        current = current->Right();
    }
    cout<<current->Key()<<endl;
};

void associativeArray::save_file(string name){
    ofstream outfile;
    outfile.open(name.c_str());
    if (outfile.fail()){
		cout<<"cout unable to open file";
	}

	saveHelper(root, outfile);

	outfile.close();

};

void associativeArray::saveHelper(Node *current, ofstream& out){
    if(current != NULL) {
        saveHelper(current->Left(),out);
        out << current -> Key() << " - " << current -> Data();
        saveHelper(current->Right(),out);
    }
};

void associativeArray::deleteNode(string key){
    deleteHelper(root, key);
};

void associativeArray::deleteHelper(Node* parent, string key){
    if(parent == NULL)
        return;

    while(parent -> Left() -> Key() != key && parent -> Right() -> Key() != key){
        if(key < parent -> Key()) //Go Left
            deleteHelper(parent -> Left(), key);
        if(key > parent -> Key()) //Go Right
            deleteHelper(parent -> Right(), key);
    }


    if(parent -> Right() -> Key() == key) //Key Found right
    {
        Node* c1 = parent -> Right();
        if(c1 -> Right() == NULL && c1 -> Left() == NULL) //Node is Leaf
        {
            parent -> setRight(NULL);
            delete c1;
        }

    else if(c1 -> Right() == NULL && c1 -> Left() != NULL) //Left Tree exists
    {
        parent -> setRight(c1 -> Left());
        delete c1;
    }

    else if(c1 -> Right() != NULL && c1 -> Left() == NULL) //Right tree exists
    {
        parent -> setRight(c1 -> Right());
        delete c1;
    }

    else //Both Trees exist
    {
        Node* child = c1 -> Left();
        while(child->Key() < child->Right()->Key() && child->Right() != NULL)
        child = child->Right();
        c1 -> setKey(child->Key());
        c1 -> setData(child->Data());
        delete child;
    }
    }

    else if(parent -> Left() -> Key() == key) //Key found left
    {
        Node* c1 = parent -> Left();
    if(c1 -> Right() == NULL && c1 -> Left() == NULL) //Node is Leaf
    {
        parent -> setLeft(NULL);
        delete c1;
    }
    else if(c1 -> Right() == NULL && c1 -> Left() != NULL) //Left Tree exists
    {
        parent -> setLeft(c1 -> Left());
        delete c1;
    }

    else if(c1 -> Right() != NULL && c1 -> Left() == NULL) //Right tree exists
    {
        parent -> setLeft(c1 -> Right());
        delete c1;
    }

    else //Both Trees exist
    {
        Node* child = c1 -> Left();
        while(child->Key() < child->Right()->Key() && child->Right() != NULL)
        child = child->Right();
        c1 -> setKey(child->Key());
        c1 -> setData(child->Data());
        delete child;
    }
}
}

