#include<iostream>


class Node{
    public:
        int key;
        int height;
        Node* leftChild;
        Node* rightChild;


    Node(int key):key(key),leftChild(nullptr),rightChild(nullptr),height(0){};

};

int max(int a, int b) { return a>b? a : b; }

int getHeight(Node* root){

    if(root==NULL){
        return -1;
    }
    return (root->height);
}
// update height
int updateHeight(Node* root){

    if ( root == NULL )    
        return -1;

    return max(getHeight(root->rightChild),getHeight(root->leftChild)) + 1;

}


int getBalanceFactor(Node* root){

    if(root==NULL){
        return 0;
    }

    return ( getHeight(root->leftChild) - getHeight(root->rightChild));
}


// rotate right
Node* rotateRight(Node* root){

    // grab left child
    Node* left = root->leftChild;
    
    // right of left child
    Node* rightLeft = left->rightChild;

    left->rightChild = root;

    root->leftChild = rightLeft;

    // return the new root which would be the left child
    root->height = updateHeight(root);
    left->height = updateHeight(left);
    return left;
}

// rotate left
Node* rotateLeft(Node* root){

    Node* right = root->rightChild;

    Node* leftRight = right->leftChild;

    right->leftChild = root;

    root->rightChild = leftRight;

    // update the heights, root first since it is down
    root->height = updateHeight(root);
    right->height = updateHeight(right);

    return right;
}

// insert

Node* insert( Node* root, int value ){

    // normal BST insert
    if(root==NULL){
        return new Node(value);
    }

    if(value>root->key){
       root->rightChild =  insert(root->rightChild,value);
    }
    else if(value<root->key){
        root->leftChild = insert(root->leftChild,value);
    }

    // fix balance factor
    root->height = updateHeight(root);

    int balance = getBalanceFactor(root);

    if(balance >1 && value < root->leftChild->key){

        return rotateRight(root);
    }
    
    if(balance < -1 && value> root->rightChild->key){

        return rotateLeft(root);
    }

    if(balance >1 && value > root->leftChild->key){

        root->leftChild = rotateLeft(root->leftChild);

        return rotateRight(root);

    }

    if(balance< -1 && value< root->rightChild->key){

        root->rightChild = rotateRight(root->rightChild);

        return rotateLeft(root);
    }

    return root;


}


// traversals
void preOrderTraversal(Node* root){

    if(root==NULL) return;

    std::cout<<root->key<<" ";
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);


}
void inOrderTraversal(Node* root){

    if(root==NULL) return;

    inOrderTraversal(root->leftChild);
    std::cout<<root->key<<" ";
    inOrderTraversal(root->rightChild);

}
void postOrderTraversal(Node* root){

    if(root==NULL) return;

  
    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    std::cout<<root->key<<" ";


}
void displayTree(Node* root){

    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout<<std::endl;

    std::cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    std::cout<<std::endl;

    std::cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    std::cout<<std::endl;
}
void clearBST(Node** root) {
    if (*root == nullptr) return;

    clearBST(&(*root)->leftChild);
    clearBST(&(*root)->rightChild);
    delete *root;
    *root = nullptr;
}





int main(){

 Node* thirdSequenceTree = nullptr;

    std::cout << "Inserting the  the third sequence into BST...\n";
    int sequence3[] = {10, 20, 30, 40, 50, 25};
    for (int num : sequence3) {
        std::cout<<"INSERTING:  "<<num<< std::endl;
        thirdSequenceTree = insert(thirdSequenceTree,num);
    }
    
    displayTree(thirdSequenceTree);
    
    clearBST(&thirdSequenceTree);

}