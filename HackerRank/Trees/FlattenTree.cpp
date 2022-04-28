/*GIVEN A BINARY TREE, FLATTEN IT INTO A LINKED LIST IN-PLACE. AFTER FLATTENING,
LEFT OF EACH NODE SHOULD POINT TO NULL AND RIGHT SHOULD CONTAIN THE NEXT
NODE IN PREORDER SEQUENCE*/

#include <iostream>
#include <stack>
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


void flatten(Node* root){
    static Node* prev = NULL;
    if(root == NULL){
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flattenstack(Node* root){
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* tmp = st.top();
        st.pop();

        if(tmp->right){
            st.push(tmp->right);
        }
        if(tmp->left){
            st.push(tmp->left);
        }

        if(!st.empty()){
            tmp->right = st.top();
        }
        tmp->left = NULL;
    }
}

void inorderprint(Node* root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
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
    root->right->left->left = new Node(7);
    root->right->right = new Node(6);

    flatten(root);
    cout << endl;
    flattenstack(root);
    inorderprint(root);
    return 0;

}