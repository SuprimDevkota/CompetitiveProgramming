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

void insert_at_head(node* &head, int val)
{
    node* new_head = new node(val);
    new_head->next = head;
    head = new_head;
}

void insert_at_tail(node* &head, int val)
{
    node* new_tail = new node(val);
    if(head == NULL){
        head = new_tail;
        return;
    }

    node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new_tail;
}

void search_and_delete(node* &head, int val)
{
    node *tmp = head;

    if(head == NULL){
        cout << "Empty linked list";
        return;
    }
    if(tmp->data == val){       //different algo for deleting at head
        node* todelete = head;
        head = tmp->next;
        delete todelete;        
        return;
    }
    while(tmp->next->data != val){
        tmp = tmp->next;
    }
    
    node *todelete = tmp->next;
    tmp->next = tmp->next->next;

    delete todelete;    //delete is important to prevent memory leak
}

void display(node* head)
{
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node* head = NULL;
    insert_at_tail(head, 1);
    insert_at_head(head, 43);
    insert_at_tail(head, -19);
    insert_at_head(head, 33);
    display(head);
    search_and_delete(head, 1);
    display(head);
    return 0;
}