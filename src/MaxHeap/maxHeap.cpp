#include<iostream>
using namespace std;



class MaxHeap{

    private:
        int size;
        int capacity;
        int* A; // store an array representation of tree

    void swap(int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return (i*2)+1;
    }
    int rightChild(int i){
        return leftChild(i)+1;
    }


    void heapifyUp(int i){
      while( i>0 && A[i]>A[parent(i)]){
        swap(i,parent(i));
        i=parent(i);
      }
    }


   void heapifyDown(int i){
    while (i < size) {
        int leftIdx = leftChild(i);
        int rightIdx = rightChild(i);
        int largestIdx = i;

        if (leftIdx < size && A[leftIdx] > A[largestIdx]) {
            largestIdx = leftIdx;
        }

        if (rightIdx < size && A[rightIdx] > A[largestIdx]) {
            largestIdx = rightIdx;
        }

        if (largestIdx != i) {
            swap(i, largestIdx);
            i = largestIdx;
        } else {
            break;
        }
    }

    }


    public:
        // constructor
        MaxHeap(int capacity){
            A = new int[capacity];
            size=0;
            this->capacity=capacity;
        }

        void insert(int number){

            if( size<capacity){
                // add the item to the last
                A[size]= number;
                // heapify up the item in size
                heapifyUp(size);
                size++;
            }
        }

        int peak(){
            return A[0];
        }

        int extractMax(){

            int largest = A[0];
            // put the last element as the root
            A[0] = A[size];

            // heapify down the root to maintain valid heap
            heapifyDown(0);
            // reduce the size
            size--;
            return largest;
        }

};

int main(){

     srand(time(NULL));
    MaxHeap* heap = new  MaxHeap(40);

    for(int i=0;i<40;i++){

        heap->insert( rand()%1000 +1);

    }


    for(int i=0;i<40;i++){

    cout<<heap->extractMax()<<endl;

    }


}