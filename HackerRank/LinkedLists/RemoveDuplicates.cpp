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

node* removeDuplicates(node* &head) {
    if (head == NULL){
        cout << "NULL";
    }

    else{
        node* dummy = new node(-1);
        node* answer = dummy;
        node* tmp = head;

        while(tmp->next != NULL){
        
        if(tmp->data != tmp->next->data){
            answer->next = tmp;
            answer = answer->next;
            }
        tmp = tmp->next;
        } 
    answer->next = tmp;
    
    return dummy->next; 

    }
      
}

int main(){
    
    node* head = NULL;
    insert_head(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 3);
    insert_tail(head, 3);
    insert_tail(head, 4);
    display(head);

    head = removeDuplicates(head);
    display(head);

    return 0;
}

