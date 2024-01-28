#include <iostream>

// Define a class for a linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

void insert_back(Node * head,int data){


    Node* newNode = new Node(data);
    Node* curr = head;

    //iterate until you reach the last element of list
    while(curr->next !=NULL){
        curr = curr->next;
    }

    curr->next = newNode;
}

void insert_front(Node ** head, int data){

    // make a new node
    Node* newNode = new Node(data);


    // point new node to head
    newNode->next = *head;

    //point head to new node
    *head = newNode;
}

void remove_front(Node ** head){

    if(*head == nullptr){
        return;
    }


    Node* temp = *head;

    *head= (*head)->next;
    delete temp;
    
}

void remove_back(Node ** head){
    // if list empty then 
     if(*head == nullptr){
        return;
    }

    Node* cur = *head;

    //if there is one element reposition the head
    if ((*head)->next == nullptr){
        Node * temp = *head;
        *head = (*head)->next;
        delete temp;

    }

    // go to the node before the last node
    while(cur->next!=NULL && cur->next->next!=NULL){

        cur= cur->next;
    }
    Node * temp  = cur->next;
    cur->next=NULL;
    delete temp;
}

void insert_at_index(Node ** head,int data, int index){



    int currIndex = 0;

    if (*head == NULL){
        return;
    }
    
    if (index==0){

        Node* newNode = new Node(data);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node * curr = *head;

    while (curr->next!=NULL && currIndex<index-1){
        
        curr= curr->next;
        currIndex++;
    }
    if (currIndex!=index-1){
        std::cout<<"Index is not in bound"<<std::endl;
        return;
    }

    //make  a new node
    Node* newNode = new Node(data);

    // insert it 
    newNode->next = curr->next;
    curr->next = newNode;

}


void print_linkedList(Node *head){
    
  
    if (head ==NULL){
        return;
    }
      std::cout<<head->data<<std::endl;
   
    return print_linkedList(head->next);
}
int main() {
    // Declare variables of the new type
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate memory for the nodes
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

   

    // Assign data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    Node* sortedLinkedList = new Node(0);

    insert_back(sortedLinkedList,1);
    insert_back(sortedLinkedList,2);
    insert_back(sortedLinkedList,3);
    insert_back(sortedLinkedList,4);
    insert_back(sortedLinkedList,5);

   
    print_linkedList(sortedLinkedList);


    insert_back(head,4);
    insert_front(&head,0);
    remove_front(&head);
    remove_back(&head);
    insert_at_index(&head,4,1);

    // Print the data in the linked list
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    delete sortedLinkedList;

    return 0;
}
