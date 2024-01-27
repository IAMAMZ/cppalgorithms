#include<iostream>
#include <time.h>




void insertion_sort(int arr[],int size){

    for(int i=1;i<20;i++)
    {
        int cur = arr[i];
        int  j = i-1;
        while (j>=0 && arr[j]>cur){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = cur;

    }

}

int main(){
    srand(time(0));
    int arr[20];

    for(int i=0;i<20;i++){
        arr[i]= rand() % 20 + 1;
    }
    
   insertion_sort(arr,20);
    for( int i=0;i<20;i++){
        std::cout<<arr[i]<<std::endl;
    }


}