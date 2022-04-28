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


Node* insertBst(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBst(root->left, val);
    }
    else{
        root->right = insertBst(root->right, val);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(5);
    insertBst(root, 2);
    insertBst(root, 1);
    insertBst(root, 3);
    insertBst(root, 7);
    insertBst(root, 6);
    insertBst(root, 9);
    inorder(root);
}