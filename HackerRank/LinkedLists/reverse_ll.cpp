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

void add_tail(node* &head, int val)
{
    node* tail = new node(val);
    if(head == NULL){
        head = tail;
        return;
    }

    node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = tail;
}

void display(node* head)
{
    node*tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

node* reverse_recursive(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node* new_head = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

node* reverse_iterative(node* &head)
{
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

int main()
{
    node* head = NULL;
    add_tail(head, 4);
    add_tail(head, 3);
    add_tail(head, 2);
    add_tail(head, 1);
    display(head);

    node* new_head = reverse_iterative(head);
    display(new_head);

    node* new_new_head = reverse_recursive(new_head);
    display(new_new_head);

    return 0;
}