#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};


Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left != NULL){
        return left;
    }

    return right;
}


int find_distance(Node* root, int k, int dist){
    if(root == NULL){
        return -1;
    }

    if(root->data == k){
        return dist;
    }

    int left = find_distance(root->left, k, dist + 1);
    if(left != -1){
        return left;
    }
    
    return find_distance(root->right, k, dist + 1);
}


int shortest_distance(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);
    int d1 = find_distance(lca, n1, 0);
    int d2 = find_distance(lca, n2, 0);

    return d1 + d2;
}


int main(){

    /*
                1
               / \
              2   3
             /   / \
            4   5   6
               /
              7 
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    cout << shortest_distance(root, 7, 6);

}