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
    for(int i = start; i<=end; ++i){
        if(inorder[i] == current){
            return i;
        }
    }
    return -1;
}

Node* BuildTree(int postorder[], int inorder[], int start, int end, int n){
    static int idx = n;

    if(start > end){
        return NULL;
    }

    int current = postorder[idx];
    idx--;
    Node* node = new Node(current);
    
    if(start == end){
        return node;
    }

    int pos = search(inorder, start, end, current);
    node->right = BuildTree(postorder, inorder, pos+1, end, n);
    node->left = BuildTree(postorder, inorder, start, pos-1, n);
}

Node* postprint(Node* root){
    if(root == NULL){
        return NULL;
    }
    postprint(root->left);
    postprint(root->right);
    cout << root->data << " ";
}

int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    int n = sizeof(postorder)/sizeof(postorder[0]) - 1;
    Node* root = BuildTree(postorder, inorder, 0, 4, n);
    postprint(root);
    return 0;
}