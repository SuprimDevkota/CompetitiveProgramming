#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert_tail(node* &head, int val)
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
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

int length_ll(node* head)
{
    node* tmp = head;
    int length = 0;
    while(tmp != NULL)
    {
        length++;
        tmp = tmp->next;
    }

    return length;
}

node* append_k_nodes(node* &head, int k)
{    
    node* new_head;
    node* new_tail;
    node* tail = head;

    int l = length_ll(head);
    k = k % l;
    int count  = 1;

    while(tail->next != NULL)
    {
        if(count == l -  k){
            new_tail = tail;
        }

        if(count == l - k + 1){
            new_head = tail;
        }

        count++;
        tail = tail->next;
    }
    tail->next = head;
    new_tail->next = NULL;

    return new_head;
}

int main()
{
    node* head = NULL;
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    display(head);
    display(append_k_nodes(head, 3));
    return 0;
}