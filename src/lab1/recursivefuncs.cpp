
#include<iostream>

int fib(int n){

    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int factorial(int n){

    if (n==0){
        return 1;
    }

    return factorial(n-1)*n;

}
int main(){

    std::cout<<factorial(5)<<std::endl;
}

