//HEIGHT OF BINARY TREE MEANS THE DEEPEST NODE LEVEL - ROOT NODE LEVEL
//DIAMETER OF BINARY TREE = NUMBER OF NODES BETWEEN THE LONGEST PATH BETWEEN TWO LEAVES
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
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

int optimizeddiameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lheight = 0, rheight = 0;
    int ldia = optimizeddiameter(root->left, &lheight);
    int rdia = optimizeddiameter(root->right, &rheight);

    int currdia = lheight +rheight + 1;
    *height = max(lheight, rheight) + 1;

    return max(currdia, max(ldia, rdia));
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdia = lheight + rheight + 1;

    int ldia = diameter(root->left);
    int rdia = diameter(root->right);

    return(max(currdia, max(ldia, rdia)));
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
    root->right->right->right = new Node(8);

    cout << height(root) <<endl;
    cout << diameter(root) << endl;

    int height = 0;
    cout << optimizeddiameter(root, &height);

}