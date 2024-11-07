#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*par;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->par = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

void construct(Node*root, Node*leaf, int val){
    Node*temp = new Node(val);
    if(root == NULL){
        root = temp= leaf;
    }
    else{
        if(leaf->left != NULL){
            temp->par = leaf;
            leaf->left = temp;
        }
        else if(leaf->right != NULL){
            temp->par = leaf;
            leaf->right = temp;
        }
        else leaf = leaf->left;
    }

}
int mian(){

}
