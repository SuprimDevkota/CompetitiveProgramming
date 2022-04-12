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

int length_ll(node* head)
{
    node* tmp = head;
    int l = 0;
    while(tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    return l;
}


void intersect(node* &head1, node* &head2, int pos)
{
    
}

int intersection_point(node* head1, node* head2)
{
    int l1 = length_ll(head1);
    int l2 = length_ll(head2);
    int d;
    node* ptr1;     //ptr1 and ptr2 point to the bigger and smaller linked list respectively
    node* ptr2;
    if(l1 > l2){
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else{
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }

    while(d)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return -1;
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
    
}


int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    int arr1[] = {1, 2, 3, 4, 5 ,6};
    int arr2[] = {9, 10, 5, 6};

    for(int i = 0; i < 6; ++i)
        add_tail(head1, arr1[i]);

    for(int i = 0; i < 4; ++i)
        add_tail(head2, arr2[i]);

    display(head1);
    display(head2);

    cout << intersection_point(head1, head2);


    return 0;
}