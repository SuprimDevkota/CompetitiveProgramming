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

int search(int inorder[], int start, int end, int current){
    for(int i = start; i <= end; ++i){
        if(inorder[i] == current){
            return i;
        }
    }
    return -1;
}

Node* BuildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int current = preorder[idx];
    idx++;
    Node* node = new Node(current);
    if(start == end){
        return node;
    }
    int pos = search(inorder, start, end, current);
    node->left = BuildTree(preorder, inorder, start, pos-1);
    node->right = BuildTree(preorder, inorder, pos+1, end);
}

void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node* root = BuildTree(preorder, inorder, 0, 4);
    inorderprint(root);
}
