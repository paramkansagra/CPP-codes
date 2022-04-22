#include <iostream>

using namespace std;

class A{
    public:
        int number1;
        void printNumber1(){
            cout<<number1<<endl;
        }
};

class B: public A{
    public:
        int number2;
        void printNumber2(){
            cout<<number2<<endl;
        }
};

class C: public A{
    public:
        int number3;
        void printNumber3(){
            cout<<number3<<endl;
        }
};