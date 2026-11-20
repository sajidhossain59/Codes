#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       vector<Node*> children;
       Node(int val){
        data=val;
       }
};


void addChild(Node*parent, Node*child){
    parent->children.push_back(child);
}

void printChildren(Node*node){
    cout<<node->data<<"->";
    for(auto childs:node->children){
        cout<<childs->data<<" ";
    }
    cout<<endl;
    for(auto childs:node->children){
        printChildren(childs);
    }
}


int main(){
    Node* root = new Node(1);
    Node* ch1 = new Node(2);
    Node* ch2 = new Node(3);
    Node* ch3 = new Node(4);
    addChild(root,ch1);
    addChild(root,ch2);
    addChild(ch1,ch3);
    printChildren(root);
}