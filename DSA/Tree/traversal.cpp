#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL; 
        }
};


void inOrder(Node*node , vector<int>&res){
    if(node == NULL)return;
    inOrder(node->left,res);
    res.push_back(node->data);
    inOrder(node->right,res);
}

void preOrder(Node*node, vector<int>&res){
    if(node==NULL)return;
    res.push_back(node->data);
    preOrder(node->left,res);
    preOrder(node->right,res);
}

void postOrder(Node*node, vector<int>&res){
    if(node == NULL)return;
    postOrder(node->left,res);
    postOrder(node->right,res);
    res.push_back(node->data);
}

int main(){
    vector<int>inOrderarray;
    vector<int>preOrderarray;
    vector<int>postOrderarray;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    inOrder(root,inOrderarray);
    preOrder(root,preOrderarray);
    postOrder(root,postOrderarray);
    cout<<"Inorder: ";
    for(auto i:inOrderarray){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Preorder: ";
    for(auto i:preOrderarray){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Postorder: ";
    for(auto i:postOrderarray){
        cout<<i<<" ";
    }
    
}
