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
    while(tmp != NULL){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}


node* merge(node* &head1, node* &head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummy_node = new node(-1);
    node* ptr3 = dummy_node;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }

        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;
    }

    while(ptr1 != NULL){
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummy_node->next;
}

int main()
{
    int arr1[] = {1, 3, 4, 5,  7, 9};
    int arr2[] = {-1, 2, 4, 6, 6, 8};

    node *head1 = NULL;
    node* head2 = NULL;

    for(int i = 0; i < sizeof(arr1)/sizeof(int); ++i)
        insert_tail(head1, arr1[i]);

    for(int i = 0; i < sizeof(arr2)/sizeof(int); ++i)
        insert_tail(head2, arr2[i]);

    display(head1);
    display(head2);

    display(merge(head1, head2));
    return 0;
}