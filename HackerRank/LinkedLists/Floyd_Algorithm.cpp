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
    node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void make_cycle(node* &head, int pos)
{
    node* tmp = head;
    node* startpos;

    int count = 1;

    while(tmp->next != NULL){
        if(count == pos){
            startpos = tmp;
        }
        tmp = tmp->next;
        count++;
    }
    tmp->next = startpos;
}

bool detect_cycle(node* head)
{
    node* hare = head;
    node* tortoise = head;

    while(hare != NULL && hare->next != NULL)   //the fast pointer's next value should also be checked because if it is NULL, the NULL's next can't be accessed.
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(hare  == tortoise){
            return true;
        }
    }

    return false;
}

void remove_cycle(node* &head)
{
    node* hare = head;
    node* tortoise = head;

    if(!detect_cycle(head)){
        return;
    }

    do{
        tortoise = tortoise->next;
        hare = hare->next->next;
    } while(tortoise != hare);

    hare = head;

    while(hare->next != tortoise ->next){
        hare = hare->next;
        tortoise = tortoise->next;
    }

    tortoise->next = NULL;
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
    make_cycle(head, 3);
    remove_cycle(head);
    display(head);
    return 0;
}