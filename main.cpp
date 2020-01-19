#include <iostream>
#include "bst.cpp"

int main(){
    BST b1;
    Node* new_Node1=new Node();
    new_Node1->data=7;
    Node* new_Node2=new Node();
    new_Node2->data=9;
    Node* new_Node3=new Node();
    new_Node3->data=8;
    Node* new_Node4=new Node();
    new_Node4->data=3;
    Node* new_Node5=new Node();
    new_Node5->data=5;
    Node* new_Node6=new Node();
    new_Node6->data=2;
    Node* new_Node7=new Node();
    new_Node7->data=10;
    b1.addBST(b1.root,new_Node1);
    b1.addBST(b1.root,new_Node2);
    b1.addBST(b1.root,new_Node3);
    b1.addBST(b1.root,new_Node4);
    b1.addBST(b1.root,new_Node5);
    b1.addBST(b1.root,new_Node6);
    b1.addBST(b1.root,new_Node7);
    b1.preorderTraverse(b1.root);

    if(b1.searchBST(b1.root,7)){
        cout<<"Number found"<<endl;
    }
    else{
        cout<<"Number not found"<<endl;
    }
    b1.deleteBST(b1.root,7);
    b1.preorderTraverse(b1.root);
    if(b1.searchBST(b1.root,7)){
        cout<<"Number found"<<endl;
    }
    else{
        cout<<"Number not found"<<endl;
    }
}