#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* node = q.front(); //Node to be analayzed
        q.pop();

        if(node){
            cout << node->data << " ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int SumatK(Node* root, int k){
    if(root == NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        
        if(node)
        {
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(level == k){
                sum +=node->data;
            }
        }

        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){

    //Create a tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    LevelOrderTraversal(root);
    cout << endl;

    int k = 2;   //k = {0,1,2...}
    cout << SumatK(root, k) << endl;
    return 0;
}