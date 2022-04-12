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

node* reverse_k(node* &head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != NULL)
    {
        head->next = reverse_k(nextptr, k);     //nextptr will point to the (k+1)th node
    }

    return prevptr;
}

int main()
{
    node* head = NULL;
    add_tail(head, 1);
    add_tail(head, 2);
    add_tail(head, 3);
    add_tail(head, 4);
    add_tail(head, 5);
    add_tail(head, 6);
    display(head);
    display(reverse_k(head, 3));
    return 0;
}