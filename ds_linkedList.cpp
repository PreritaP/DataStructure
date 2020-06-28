#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int k) {
    struct Node* temp = new Node;
    temp->data = k;
    temp->next = NULL;
    return temp;
}

void printlist(struct Node* head) {
    while(head) {
        cout<<head->data;
        if(head->next)
            cout<<" ---> ";
        head = head->next;
    }
    cout<<endl;
}

// rearrange l1->ln->l2->ln-1->l3->ln-2...
void rearrange(struct Node** head, struct Node* last ){
    if(!last)   //base case
        return;
    rearrange(head, last->next);
    if(!(*head)->next) 
        return;
        
    if((*head) != last && (*head)->next != last) {
        struct Node* temp = new Node;
        temp = (*head)->next;
        (*head)->next = last;
        last->next = temp;
        *head = temp;
    } else {
        if ((*head) != last)
            *head = (*head)->next;
        (*head)->next = NULL;
    }
}

//merge two sorted ll
Node* sortedMerge(struct Node* a, struct Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    struct Node* result;
    if(a->data < b->data){
        result = a;
        result->next = sortedMerge(a->next,b);
    } else {
        result = b;
        result->next = sortedMerge(a,b->next);
    }
}

//detect a loop in a ll and print the node
int detectCycle(struct Node* root) {
    Node* slow = root;
    Node* fast = root;
    while(slow && fast && fast->next){
        slow= slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<slow->data<<endl;
            cout<<"found loop"<<endl;
            return 1;
        }
    }
    return 0;
}

//check palindrome
int isPalUtil(struct Node** left, struct Node* right){
    if(right==NULL) return true;
    
    bool check = isPalUtil(left, right->next);
    if(check == false) return false;
    
    bool isPal = ((*left)->data == right->data); 
    
    (*left)= (*left)->next;
    return isPal;
}

int isPalindrome(struct Node* head){
    return isPalUtil(&head, head);
}

//add two numbers represented by a ll
Node* addTwoNumbers(Node* a, Node* b){
    Node* result = NULL;
    Node *temp, *prev;
    int carry=0, sum=0;
    
    while(a!=NULL || b!=NULL){
        sum = carry + (a?a->data:0) + (b?b->data:0);
        carry = (sum>10)? 1 : 0;
        sum = sum%10;
        temp = newNode(sum);
        if(result==NULL)
            result=temp;
        else
            prev->next = temp;
        prev=temp;
        
        if(a) a=a->next;
        if(b) b=b->next;
    }
    if(carry>0)
        temp->next=newNode(1);
    return result;
}

// skip m nodes and delete n nodes
void skipMdeleteN(Node* head, int m, int n){
    Node* curr = head, *temp;
    while(curr){
        
        for(int i=1;i<m && curr!=NULL;i++){
            curr=curr->next;
        }
        
        if(curr == NULL) return;
        
        temp = curr->next;
        for(int i=1;i<=n && temp!=NULL;i++){
            Node* a = temp;
            temp = temp->next;
            free(a);
        }
        curr->next = temp;
        curr = temp;
    }
}

node *reverse (struct node *head, int k) { 
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  

    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  

    if (next != NULL)  
    head->next = reverse(next, k);  

    return prev; 

}

int main() {
    struct Node* head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(7);
    printlist(head);
    
    struct Node* headA = newNode(5);
    headA->next = newNode(5);
    headA->next->next = newNode(5);
    printlist(headA);
    
    struct Node* addedNo = addTwoNumbers(head, headA);
    printlist(addedNo);
    
    skipMdeleteN(head, 2, 2);
    printlist(head);
    
    //head->next->next->next->next->next->next = head;
    //cout<<detectCycle(head);
    
    //cout<<isPalindrome(head);

    //printlist(head);
    
    //  struct Node* headA = newNode(1);
    //  headA->next = newNode(3);
    //  headA->next->next = newNode(6);
    //  headA->next->next->next = newNode(7);
    //  headA->next->next->next->next = newNode(9);
    //  printlist(headA);
        
    //  struct Node* newHead = sortedMerge(head, headA);
    //  printlist(newHead);

	// struct Node* head = newNode(1);
	// head->next = newNode(2);
	// head->next->next = newNode(3);
	// head->next->next->next = newNode(4);
	// head->next->next->next->next = newNode(5);
	// printlist(head);
	// struct Node* temp = head;
	// rearrange(&temp, head);
	// printlist(head);
}