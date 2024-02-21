#include<iostream>


class Vector{

    int capacity;
    int n; // number of elements in vector
    int* A; // array sorting elements

    public:
    Vector(int capacity=10):capacity(capacity),n(0){
        
        A= new int[capacity];
        
    }
    void reserve(int N){ //N--> is number of elements to be reserved, n--> is number of elements in current
        if(capacity>=N){ return;}

        //make a new array
        int* B = new int[N];

        // copy from a to B
        for(int i=0;i<n;i++){ // 
            B[i] = A[i];
        }
        if(A!=NULL){delete[] A;}

        A=B; // point A to the new array
        capacity = N; // update capacitys

    }

    ~Vector(){delete[] A;}




    int size(){return n;}
    bool empty(){return n==0;}
    int at(int i){
        if(i>=n || i<0){
            std::cout<<"Acessing element out of range, fail"<<std::endl;
            return -1;
        }
        return A[i];
    }
    void erase(int i){

        if(this->empty()){
            std::cout<<"cannot erase from an empty vector"<<std::endl;
            return;
        }
        if(i<n && i>=0){

            // move all elements left of i to left
            for(int j=i+1;j<n;j++){
                A[j-1] = A[j];
            }
            // update number of elements
            n--;

        }
        // if vector number of elements is 1/4 of size

        if(n<capacity/4){
            // shring the capacity
            reserve(capacity/2);
        }


    }
    void insert(int i,int data){

        if(n>=capacity){
            // double the array if i is larger than capacity
            reserve(capacity*2);
        }

        // check for out of bound access
        if(i<0 || i>n){
            std::cout<<"Insertion index out of bound"<<std::endl;
            return;
        }
        
        // move everything to the right to make room
        for(int j = n-1;j>=i;j--){
            A[j+1] = A[j];
        }
        // insert data after i
        A[i] = data;
        // update size
        n++;

    }




};

int main(){

    Vector* v = new Vector();

    for(int i=0;i<100; i++){
        v->insert(i,i);
    }

    // print
    for(int i=0;i<100;i++){

        std::cout<<v->at(i)<<std::endl;
    }
    return 0;
}