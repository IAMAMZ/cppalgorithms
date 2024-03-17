#include<iostream>


class Node {
    public:
    int data;
    Node* right;
    Node* left;
    //constructor
    Node(int data = 0):data(data),left(nullptr),right(nullptr){};
};


// insert

void Treeinsert(Node** root, int dataToInsert){


    // make a new node
    Node* newNode = new Node(dataToInsert);
    if(*root==nullptr){
        *root = newNode;
        return;
    }

    Node* curr = *root;

    while( curr!= NULL){

        if(curr->data > dataToInsert){
            // if left of current is empty enter it there
            if(curr->left == nullptr){
                curr->left = newNode;
                return;
            }
            curr=curr->left;
        }
        else if ( curr->data < dataToInsert){
              if(curr->right == nullptr){
                curr->right = newNode;
                return;
            }
            curr=curr->right;
        }
    }
}


// find an element

// traversals

void preOrderTraversal(Node* root){

    if(root==nullptr){
        return;
    }

std::cout<<root->data<<std::endl;

preOrderTraversal(root->left);
preOrderTraversal(root->right);

}


int main(){


    Node* myTree = new Node(10);

    Treeinsert(&myTree,20);
    Treeinsert(&myTree,5);
    Treeinsert(&myTree,40);
    preOrderTraversal(myTree);

}