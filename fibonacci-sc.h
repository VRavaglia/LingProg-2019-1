#ifndef FIBONACCI_H
#define FIBONACCI_H


int fibonacci (int n);
class Fibonacci{
    public:
        void computeFibonacci(int n);
        int getFib();
    private:
        int result;
        void setFib(int result);
        
};

#endif