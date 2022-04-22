#include<iostream>
 
using namespace std;
 
class A{
    public:
        int a,b;

        int add(){
            return a+b;
        }
        void operator +(A &obj){
            int value1 = this->a - obj.a;
            cout<<value1<<endl;
        }

        void operator() (){ // -> overloading ()
            cout<<"mai bracket hu"<<endl;
        }
};

int main(){
    
    A obj1,obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1+obj2;
    obj1();

    return 0;
}