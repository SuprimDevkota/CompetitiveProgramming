#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;

        node(int val){
            data = val;
            prev = NULL;
            next = NULL;
        }
};

void inserthead(node* &head, int val){
    node* new_head = new node(val);
    if(head != NULL){
        new_head->next = head;
        head->prev = new_head;
    }
    head = new_head;
}

void display(node* head){
    node* tmp = head;
    while(tmp != NULL){
        if(tmp->next != NULL)
        {
            cout << tmp->data << " <---> ";
        }
        else{
            cout << tmp->data << " ---> ";
        }
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void inserttail(node* &head, int val){
    node* tail = new node (val);
    if(head == NULL){
        head = tail;
        return;
    }
    node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = tail;
    tail->prev = tmp;
}

node* reverse(node* &head){
    if(!head) return head;
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}


int main(){
    node* head = NULL;
    inserthead(head, 1);
    inserttail(head, 2);
    inserttail(head, 3);
    inserttail(head, 4);
    display(head);
    display(reverse(head));

}