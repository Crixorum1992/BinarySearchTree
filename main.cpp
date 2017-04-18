//Name: Nicholas Reid
//Date: 04/17/2017
//program: main.cpp
//Description: Binary Search Tree

#include "Class.h"

int main(){
    string key;
    int value;
    string name;
    int choice;
    BinarySearchTree tree;

    BinarySearchTree();

    cout<<"welcome to binary search tree"<<endl;
    cout<<"1. set"<<endl;
    cout<<"2. print"<<endl;
    cout<<"3. min"<<endl;
    cout<<"4. max"<<endl;
    cout<<"5. save"<<endl;
    cout<<"6. delete"<<endl;
    cout<<"7. exit"<<endl;

    while (choice != 7){
        cout<<"how do you want to proceed"<<endl;
        cin>>choice;
        if(choice == 1){
                cout<<"Key"<<endl;
                cin>>key;
                cout<<endl;
                cout<<"Value"<<endl;
                cin>>value;
                cout<<endl;
                tree.setNode(key, value);
                cout<<"setting"<<endl;
        }
        else if (choice == 2){
            tree.print();
            cout<<"printing"<<endl;
        }
        else if (choice == 3){
            tree.minNode();
            cout<<"finding min"<<endl;
        }
        else if (choice == 4){
            tree.maxNode();
            cout<<"finding max"<<endl;
        }
        else if (choice == 5){
            cout<<"what is file name"<<endl;
            cin>>name;
            tree.save_file(name);
            cout<<"saving"<<endl;
        }
        else if (choice == 6){
            cout<<"Value"<<endl;
            cin>>value;
            cout<<"Key"<<endl;
            cin>>key;
            tree.deleteNode(value);
            cout<<"deleting"<<endl;
        }
        else if (choice == 7)
            cout<<"exiting"<<endl;
        else{
            cout<<"out of bounds"<<endl;
	}
    }

     tree.~BinarySearchTree();
}
