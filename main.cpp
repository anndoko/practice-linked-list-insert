//
//  main.cpp
//  LinkedListInsert
//
//  Created by Yu-An Ko on 2016/5/6.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head; //global variable

void Insert(int data, int n){
    
    //create a Node by makeing a call to malloc
    //struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    
    //in C++
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    
    Node* temp2 = head; //create a pointer to node: variable temp2
    for(int i = 0; i < n-2; i++){ // run a loop and go to the (n-1)th node
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Display(){
    Node* temp = head; //temporary pointer to node initially pointing to head
    cout << "List: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    head = NULL; //empty list
    Insert(2, 1); //list: 2
    Insert(3, 2); //list: 2, 3
    Insert(4, 1); //list: 4, 2, 3
    Insert(5, 2); //list: 4, 5, 2, 3
    Display(); //output: 4, 5, 2, 3
}
