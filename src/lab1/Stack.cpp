#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int capacity;
    int* array;

public:
    // Constructor
    Stack(int cap = 10) : size(0), capacity(cap) {
        array = new int[capacity]; // Allocate memory dynamically
    }

    // Destructor
    ~Stack() {
        delete[] array; // Free allocated memory
    }

    // Push operation
    void push(int data) {
        if (size >= capacity) {
            // Double the capacity if the array is full
            capacity *= 2;
            int* temp = new int[capacity];
            // Copy existing elements to the new array
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
            // Free old array and point to the new one
            delete[] array;
            array = temp;
        }
        // Add the new element
        array[size++] = data;
    }

    // Pop operation
    int pop() {
        if (size == 0) {
            cout << "Stack is empty!" << endl;
            return -1; // Indicate error or empty stack
        }
        // Return the top element and decrease the size
        return array[--size];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the current size of the stack
    int getSize() const {
        return size;
    }
};
class Node{
    public:
    int data;
    Node* next;
};

class StackLinkedList{

    private:

        int size=0;
        Node* head;

    public:

    int getSize(){
        return size;
    }

    void push(int data){

        // make a new node
        Node* newNode = new Node();
        newNode->data= data;


        newNode->next = head;
        head = newNode;

        size++;


    };

    int pop(){

        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -100000000;
        }

        int poppedData = head->data;

        Node* temp = head->next;
        
        head = head->next;

        delete temp;
        size--;

        return poppedData;
    }

    bool isEmpty(){
        return head==nullptr;
    }

};

int main() {
    Stack stack;

    StackLinkedList stackLinked;

    // Example usage
    stack.push(1);
    stack.push(2);
    cout << "Popped: " << stack.pop() << endl; // Should print 2
    cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;


    stackLinked.push(1);
    stackLinked.push(2);
    cout << "Popped: " << stackLinked.pop() << endl; // Should print 2
    cout << "stackLinked is empty: " << (stackLinked.isEmpty() ? "Yes" : "No") << endl;
    cout<<stackLinked.getSize()<<endl;

    return 0;
}
