#include "fibonacci-sc.h"
int fibonacci (int n)
{
    int fib1 = 1;
    int fib2 = 1;
    int tfib = 1;

    for (int i = 1; i <= n + 1; i++){
        if (i > 2){
            tfib = fib2;
            fib2 += fib1;
            fib1 = tfib;
        }
    }

    return tfib;
}


void Fibonacci::setFib(int a){
    result = a;
}

int Fibonacci::getFib(){
    return result;
}

void Fibonacci::computeFibonacci(int n){
    setFib(fibonacci(n));
}