#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkBst(Node* root, Node* minallow, Node* maxallow){
    if(root == NULL){
        return true;
    }

    if(minallow != NULL && root->data <= minallow->data){
        return false;
    }

    if(maxallow != NULL && root->data >= maxallow->data){
        return false;
    }

    bool leftvalid = checkBst(root->left, minallow, root);
    bool rightvalid = checkBst(root->right, root, maxallow);

    return leftvalid && rightvalid;
}

int main(){

    /*
              5
            /    \
           2      7
          / \    / \
         1   8  6   9 

    */

    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    
    cout << checkBst(root, NULL, NULL) << endl;
}