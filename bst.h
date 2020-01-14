#ifndef BST_H
#define BST_H

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};
class BST{
    public:
        Node* root=new Node();
        BST();
        ~BST();
        void addBST(Node* root, Node* newNode);
        bool searchBST(Node* root,int targetKey);
        void deleteBST(Node* root,int keytoDelete);
        void preorderTraverse(Node* root);
};
#endif