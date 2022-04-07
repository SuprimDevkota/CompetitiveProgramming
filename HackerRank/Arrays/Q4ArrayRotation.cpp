#include <iostream>
#include <vector>
using namespace std;

//USING Linked lists. SUPER INEFFECIENT:
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insert_at_tail(node*& head, int val){
    node* tail = new node(val);
    if(head == NULL){
        head = tail;
        return;
    }
    node*tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = tail;
}

void insert_at_head(node*& head, int val){
    node* new_head = new node(val);
    new_head->next = head;
    head = new_head;
}

void display(node* head){
    node* tmp = head;
    while(tmp != NULL){
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return;
    }
    cout << endl;
}

void leftrotate(node*& head, int d){
    while(d--)
    {
        node* tmp = head;
        node* new_head = NULL;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next->next = head; 
        new_head = head->next;
        head->next = NULL;
        head = new_head;
    }
}

int main(){
    node* head = NULL;
    insert_at_head(head, 1);
    for(int i = 2; i < 6; ++i){
        insert_at_tail(head, i);
    }
    display(head);
    cout << endl;
    leftrotate(head, 4);
    display(head);
    return 0;
}

//USING VECTORS SUPER EFFICIENT:
int main(){
    int n, d;
    cin >> n >> d;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    while(d--){
        int to_add = v[0];
        v.erase(v.begin());
        v.push_back(to_add);
    }

    //Print Function
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}
