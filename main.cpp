//Name: Nicholas Reid
//Date: 12/8/2017
//Program: main.cpp
//Description: main driver for the program

#include "Class.h"

main(){
    string key;
    int value;
    string name;
    int choice;
    associativeArray tree;

    associativeArray();

    cout<<"welcome to binary search tree"<<endl;
    cout<<"1. set"<<endl;
    cout<<"2. print"<<endl;
    cout<<"3. min"<<endl;
    cout<<"4. max"<<endl;
    cout<<"5. save"<<endl;
    cout<<"6. delete"<<endl;
    cout<<"7. find"<<endl;
    cout<<"8. exit"<<endl;

    while (choice != 8){
        cout<<"how do you want to proceed"<<endl;
        cin>>choice;
        if(choice == 1){
                cout<<"Key"<<endl;
                cin>>key;
                cout<<"Value"<<endl;
                cin>>value;
                tree.setNode(key, value);
                cout<<"setting"<<endl;
        }
        else if (choice == 2){
            tree.print();
            cout<<endl;
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
            cout<<"Key"<<endl;
            cin>>key;
            tree.deleteNode(key);
            cout<<"deleting"<<endl;
        }
        else if (choice == 7){
            cout<<"key"<<endl;
            cin>>key;
            tree.find(key);
        }
        else if (choice == 8)
            cout<<"exiting"<<endl;
        else{
            cout<<"out of bounds"<<endl;
            cin.clear();
            cin.ignore(1,' ');
        }
    }

     //tree.~associativeArray();
}
