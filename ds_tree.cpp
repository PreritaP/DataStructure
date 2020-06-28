#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node (int data){
        this->data = data;
        left = right = NULL;
    }
};

void InOrderTraversal(Node* root){
    if(root == NULL) return;
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root){
    if(root == NULL) return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void LevelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node *> q; 
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();
        
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

void reverseLevelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp);
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }
    
    while(!s.empty()){
        Node* temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
    }
}

void VerticalOrderTraversal(Node* root){
    if(root == NULL) return;
    map<int, vector<int>> m;
    int hd = 0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,hd));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
        m[hd].push_back(node->data);
        
        if(node->left)
            q.push(make_pair(node->left, hd-1));
        if(node->right)
            q.push(make_pair(node->right, hd+1));
    }
    
    map<int, vector<int>>::iterator i;
    for( i = m.begin(); i != m.end(); i++){
        for(int j=0; j< i->second.size(); j++)
            cout<<i->second[j]<<" ";
        cout<<endl;
    }
}

void TopView(Node* root){
    if(root == NULL) return;
    map<int,int> m;
    int hd = 0;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,hd));
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
        
        if(m.count(hd) == 0)
            m[hd]=node->data;
        
        if(node->left)
            q.push(make_pair(node->left,hd-1));
        if(node->right)
            q.push(make_pair(node->right,hd+1));
    }
    for(auto i=m.begin(); i!=m.end(); i++)
        cout<<i->second<<" ";
    
}

void BottomView(Node* root){
    if(root == NULL) return;
    map<int,int> m;
    queue<pair<Node*, int>> q;
    int hd = 0;
    q.push(make_pair(root,hd));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* node = temp.first;
        hd = temp.second;
        
        m[hd] = node->data;
        
        if(node->left)
            q.push(make_pair(node->left,hd-1));
        if(node->right)
            q.push(make_pair(node->right,hd+1));
    }
    
    for(auto i=m.begin(); i!=m.end(); i++)
        cout<<i->second<<" ";
}

void leftViewUtil(Node* root, int level, int *max_level){
    if(root == NULL) return;
    
    if(*max_level < level){
        cout<<root->data<<" ";
        *max_level = level;
    }
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}

void LeftView(Node* root){
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

void RightViewUti(Node* root, int level, int *max_level) {
    if(root == NULL) return;
    
    if(*max_level < level){
        cout<<root->data<<" ";
        *max_level = level;
    }
    RightViewUti(root->right, level+1, max_level);
    RightViewUti(root->left, level+1, max_level);
}

void RightView(Node* root){
    int max_level = 0;
    RightViewUti(root, 1, &max_level);
}

void diagonalPrintUtil(Node* root, int d, map<int, vector<int>> &dp) {
    if (root == NULL) return;
    
    dp[d].push_back(root->data);
    
    diagonalPrintUtil(root->left, d+1, dp);
    diagonalPrintUtil(root->right, d, dp);
}

void daigonalPrint(Node* root){
    map<int, vector<int>> m;
    diagonalPrintUtil(root, 0, m);
    
    for(auto i=m.begin(); i!= m.end(); i++){
        for(auto j=i->second.begin(); j!=i->second.end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }
}

int heightMin(Node* root) {
    if(!root) return 0;
    return 1 + min(heightMin(root->left), heightMin(root->right));
}

int heightMax(Node* root){
    if(!root) return 0;
    return 1 + max(heightMax(root->left),heightMax(root->right));
}

int diameter(Node* root){
    if(!root) return 0;
    
    int lh = heightMax(root->left);
    int rh = heightMax(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    
    return max(lh+rh+1, max(ld, rd));
}

void printPathArray(int a[], int len){
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void printPathUtil(Node* root, int path[], int pathlen){
    if(root == NULL) return;
    path[pathlen] = root->data;
    pathlen++;
    
    if(root->left == NULL && root->right == NULL)
        printPathArray(path,pathlen);
    else {
        printPathUtil(root->left, path, pathlen);
        printPathUtil(root->right, path, pathlen);
    }
}

void printPath(Node* root){
    int path[10000];
    printPathUtil(root,path,0);
}

Node* findlca(Node* root, int n1, int n2){
    if(!root) return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* l_lca = findlca(root->left, n1, n2);
    Node* r_lca = findlca(root->right, n1, n2);
    
    if(l_lca && r_lca)
        return root;
    return (l_lca != NULL)? l_lca : r_lca;
}

int findLevel(Node* root, int k, int level){
    if(root == NULL) return -1;
    if(root->data == k) return level;
    int left = findLevel(root->left, k, level+1);
    if(left == -1)
        return findLevel(root->right, k, level+1);
    return left;
}

int findDistance(Node* root, int n1, int n2){
    Node* lca = findlca(root, n1, n2);
    int dleft = findLevel(lca,n1,0);
    int dright = findLevel(lca,n2,0);
    return dleft + dright;
}

int evenOddDiff(Node* root){
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int level = 0, evenS = 0, oddS = 0;
    while(!q.empty()){
        int size = q.size();
        level++;
        while(size > 0){
            Node* node = q.front();
            q.pop();
            if(level % 2 == 0)
                evenS += node->data;
            else
                oddS += node->data;
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            size--;  
        }
    }
    return (oddS-evenS);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left =  new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    
    //     1
    //   / \
    //   2   3
    //  /\
    // 4  5
    //   /\
    //  6  7
    
    /* TREE TRAVERSALS */

    cout<<endl<<"In Order Traversal : ";
    InOrderTraversal(root);
    cout<<endl<<"Pre Order Traversal : ";
    PreOrderTraversal(root);
    cout<<endl<<"Post Order Traversal : ";
    PostOrderTraversal(root);
    
    cout<<endl<<"Level Order Traversal : ";
    LevelOrderTraversal(root);
    cout<<endl<<"Rever Level Order Traversal : ";
    reverseLevelOrder(root);
    
    cout<<endl<<"Vertical Order Traversal : "<<endl;
    VerticalOrderTraversal(root);

    /* VIEWS OF A TRESS */
    
    cout<<endl<<"Top View of a Tree : "<<endl;
    TopView(root);
    cout<<endl<<"Botton View of a Tree : "<<endl;
    BottomView(root);
    cout<<endl<<"Left View of a Tree : "<<endl;
    LeftView(root);
    cout<<endl<<"Right View of a Tree : "<<endl;
    RightView(root);

    /* DAIGONAL PRINT OF A TREE */
    
    cout<<endl<<"Daigonal Print : "<<endl;
    daigonalPrint(root);

    /* Min / MAX DEPTH OF A TREE */

    cout<<endl<<"Max Depth of a tree : "<<heightMax(root);
    cout<<endl<<"Min Depth of a tree : "<<heightMin(root);
    cout<<endl<<"Diameter of a Tree : "<<diameter(root);
    
    /* ROOT TO LEAD PATH */

    cout<<endl<<"Print all root to leaf path : "<<endl;
    printPath(root);
    
    /* LONGEST COMMON ANCESTOR OF TREE NODES */

    int n1 = 7;
    int n2 = 3;
    cout<<endl<<"LCA of "<<n1<<" "<<n2<<" : "<<findlca(root,n1,n2)->data;
    
    /* DISTANCE BETWEEN TWO TREE NODES */

    n1 = 2, n2 = 3;
    cout<<endl<<"Distance between "<<n1<<" "<<n2<<" : "<<findDistance(root, n1, n2);
    
    /* DIFFERENCE BETWEEN ODD AND EVEN LEVEL OF A TREE */

    cout<<endl<<"Difference between even and odd level : "<<evenOddDiff(root);
    
    return 0;
}