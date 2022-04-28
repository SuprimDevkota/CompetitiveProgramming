#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}


bool isBalanced(Node* root){

    if(root == NULL){
        return true;
    }
    
    if(!isBalanced(root->left) || !isBalanced(root->right)){
        return false;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(abs(lheight - rheight) > 1){
        return false;
    }

    return true;
}

bool OptimisBalanced(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return true;
    }

    int lheight = 0, rheight = 0;
    if(OptimisBalanced(root->left, &lheight) == false || OptimisBalanced(root->right, &rheight) == false){
        return false;
    }

    *height = max(lheight, rheight) + 1;

    if(abs(lheight - rheight) > 1){
        return false;
    }

    return true;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    cout << isBalanced(root);
    cout << endl;
    int height = 0;
    cout << OptimisBalanced(root, &height);
}