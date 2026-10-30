#include <bits/stdc++.h>
using namespace std;


typedef struct Node {
    int val;
    Node*next;
};

typedef struct Linked_List{
    Node* head;
    Node* tail;
    int size;
};

Node *createNode(int input){
    Node*nd = new Node;
    nd->val = input;
    nd->next = NULL;
    return nd;
}

Linked_List* createLinked_List(){
    Linked_List *ls = new Linked_List;
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
    return ls;
}


void insert(Linked_List*ls, int value, int pos){
    
    if (pos < 0 || pos > ls->size) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node *newnd = createNode(value);
    if(pos==0){
        newnd->next =ls->head;
        ls->head = newnd;
        if(ls->size==0){
            ls->tail = newnd;
        }
    }
    else if(pos == ls->size){
        ls->tail->next = newnd;
        ls->tail = newnd;
    }
    else{
        Node * tmp = ls->head;
        for(int i=0;i<pos-1;i++){
            tmp=tmp->next;
        }
        newnd->next = tmp->next;
        tmp->next = newnd;
    }

    ls->size++;
}


void delete(Linked_List * lst , int position){
    if (pos < 0 || pos > ls->size) {
        cout << "Invalid position!" << endl;
        return;
    }
    else{
        Node*tmp = lst->head;
        if(pos == 0)
    }
}





signed main(){

}