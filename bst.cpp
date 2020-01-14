#include <iostream>
#include "bst.h"
using namespace std;
BST::BST(){
    root=NULL;
}
BST::~BST(){}
void BST::addBST(Node* root,Node* newNode){
    if(root==NULL){
       this->root=newNode;
    }
    else{
        if(newNode->data > root->data)
		{
			if(root->right!= NULL){
				addBST(root->right,newNode);
			}
			else{
				root->right=newNode; 
			}
			
		}
		else if(newNode->data < root->data)
		{
			if(root->left!= NULL){
				addBST(root->left,newNode);
			}
			else{
				root->left=newNode; 
			}
		}
    }
}
void BST::preorderTraverse(Node* root){
	if(root==NULL){
		cout<<"There is no value to show"<<endl;
		return;
	}
		cout<<root->data<<endl;
	if(root->left!=NULL){
		preorderTraverse(root->left);
	}
	if(root->right!=NULL){
		preorderTraverse(root->right);
	}
	
}
bool BST::searchBST(Node* root,int targetKey){
    if(root==NULL){
        cout<<"It is a Null tree"<<endl;
    }
    else{
        Node *p=new Node();
        p=root;
        while(p!=NULL){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}
void BST::deleteBST(Node* root,int keytoDelete){
    int dat;
    if(root==NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    if(keytoDelete<root->data){
        Node* temp=new Node();
        temp=root->left;
        if(root->left->data==keytoDelete && root->left->left==NULL && root->left->right==NULL){
            root->left=NULL;
        }
        deleteBST(temp,keytoDelete);
        return;
    }
    else if(keytoDelete>root->data){
        Node* temp=new Node();
        temp=root->right;
        if(root->right->data==keytoDelete && root->right->left==NULL && root->right->right==NULL){
            root->right=NULL;
        }
        deleteBST(temp,keytoDelete);
        return;
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return;
        }
        else if(root->left==NULL){
            Node* temp=new Node();
            temp=root->right;
            root->data=root->right->data;
            root->right=root->right->right;
            delete temp;
            return;
        }
        else if(root->right==NULL){
            Node* temp=new Node();
            temp=root->left;
            root->data=root->left->data;
            root->left=root->left->left;
            delete temp;
            return;
        }
        else{
            Node* nodetoDelete=new Node();
            nodetoDelete=root;
            Node* newNode=new Node();
            newNode=root->left;
            while(newNode->right!=NULL){
                newNode=newNode->right;
            }
            dat=newNode->data;
            deleteBST(nodetoDelete->left,newNode->data);
            root->data=dat;
            return;
        }
    }
}