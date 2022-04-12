#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }

};

void insert_head(node* &head, int val){

    node* new_head = new node (val);
    if(head != NULL){
        new_head->next = head;
    }
    head = new_head;
}

void insert_tail(node* &head, int val){
    node* tail = new node(val);
    node* tmp = head;
    if(head == NULL){
        head = tail;
    }

    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = tail;
}

void display(node* head){
    node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data << "--> ";
        tmp = tmp->next;
    }

    cout << "NULL" << endl;
}

int GetNodeValue(node* head, int posfromtail){
    node* tmp = head;
    int nodes = 0;
    while(tmp != NULL){
        nodes++;
        tmp = tmp->next;
    }


    int posfromhead = nodes - posfromtail - 1;
    int tmp_pos = 0;
    tmp = head;
    while(tmp_pos < posfromhead && tmp != NULL){
        tmp = tmp->next;
        tmp_pos++;
    }

    return tmp->data;
}

int main(){
    node* head = NULL;
    insert_head(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    display(head);
    cout << GetNodeValue(head, 1);
}