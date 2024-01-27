#include <iostream>

// Define a class for a linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

void insert_front(Node * head,int data){

    Node* newNode = new Node(data);
    Node* curr = head;

    //iterate until you reach the last element of list
    while(curr->next !=NULL){
        curr = curr->next;
    }

    curr->next = newNode;
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

    insert_front(head,4);

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

    return 0;
}
