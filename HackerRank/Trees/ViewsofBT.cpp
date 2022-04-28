#include <iostream>
#include <queue>
using namespace std;

struct Node{
    public:
        int data;
        struct Node* left;
        struct Node* right;
    
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};


void LeftView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n; ++i){
            Node* current = q.front();
            q.pop();
            if(i == 0){
                cout << current->data << " ";
            }

            if(current->left){
                q.push(current->left);
            }

            if(current->right){
                q.push(current->right);
            }
        }
    }

    cout << endl;

}

void RightView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();       //Number of elements in the queue, changes per level of tree

        for (int i = 0; i < n; ++i){    //For each node in the level find current node and pop it from queue
            Node* current = q.front();
            q.pop();
           
            if(i == n - 1){
                cout << current->data << " ";
            }

            if(current->left != NULL){
                q.push(current->left);
            }

            if(current->right != NULL){
                q.push(current->right);
            }
        }
    }

    cout << endl;
}

int main(){
    struct Node* root1 = new Node(7);
    root1->left = new Node(6);
    root1->right = new Node(2);
    root1->left->left = new Node(5);
    root1->left->right = new Node(1);
    root1->left->right->left = new Node(4);
    root1->right->left = new Node(8);
    root1->right->right = new Node(3);
    cout << "Rightview tree 1: ";
    RightView(root1);
    cout << "Leftview tree 1: ";
    LeftView(root1);
    cout << endl;

    struct Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(1);
    root2->right->left = new Node(4);
    root2->right->left->left = new Node(6);
    root2->right->left->right = new Node(5);
    cout << "Rightview tree 2: ";
    RightView(root2);
    cout << "Leftview tree 2: ";
    LeftView(root2);
    cout << endl;
}