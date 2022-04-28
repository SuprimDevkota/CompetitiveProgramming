/*PROPERTIES OF BINARY TREE

1. MAXIMUM NODES AT LEVEL L = 2^L; L= {0,1,2...}
2. MAXIMUM NODES IN A TREE OF HEIGHT H = 2^H - 1; H = {1,2,3...}
3. FOR N NODES MINIMUM POSSIBLE HEIGHT OT MINIMUM NUMBER OF LEVELS ARE LOG2(N+1)
4. A BINARY TREE WITH L LEAVES HAS AT LEAST LOG2(N+1)+1 NUMBER OF LEVELS

*/

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

void preorder(struct Node* root){
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){

    /*  BEHOLD MORTALS, THE SPECIMEN OF A TREE!! 
                1
               / \
             2     3 
            / \   / \    
           4   5  6  7
    */

    //CREATION OF A TREE STRUCTURE
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    /*PREORDER TRAVERSAL = ROOT->LEFT SUBTREE->RIGHT SUBTREE
    EG: 1,2,4,5,3,6,7*/
    preorder(root);
    cout << endl;

    /*INORDER TRAVERSAL = LEFT SUBTREE->ROOT->RIGHT SUBTREE
    EG:4,2,5,1,6,3,7*/
    inorder(root);
    cout << endl;

    /*POSTORDER TRAVERSAL = LEFTSUBTREE->RIGHT SUBTREE->ROOT
    EG:4,5,2,6,7,3,1*/
    postorder(root);
    cout << endl;
    return 0;
}
