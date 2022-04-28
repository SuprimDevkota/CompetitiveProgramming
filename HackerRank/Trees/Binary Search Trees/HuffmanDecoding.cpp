/*

void decodehuffman(node* root, string s){
    node* tmp = root;
    for(char c: s){
        tmp = (c == '0')? tmp->left: tmp->right;

        if(tmp->data){
            cout << tmp->data;
            tmp = root;
        }
    }
}

*/