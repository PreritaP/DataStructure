#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T> 
struct Node{
T data;
Node *next;
};

template <typename T> 
Node<T>* newNode (T x) { 
   Node<T>* temp = new Node<T>;
   temp->data = x;
   temp->next = NULL;
   return temp;
}

template <typename T>
void printlist(Node<T>* root){
    if(root == NULL)
        return;
    while(root){
        cout<<root->data;
        if(root->next)
            cout<<" --> ";
            
        root= root->next;
    }
}


int main() {
    Node<int>*head = newNode<int>(1);
    head->next = newNode<int>(3);
    head->next->next = newNode<int>(2);
    head->next->next->next = newNode<int>(6);
    head->next->next->next->next = newNode<int>(3);
    head->next->next->next->next->next = newNode<int>(8);
    printlist(head);
    cout<<"" <<endl;
    Node<char>*head2 = newNode('a');
    head2->next = newNode('b');
    printlist(head2);
    
	return 0;
}