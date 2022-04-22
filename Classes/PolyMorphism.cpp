#include <iostream>

using namespace std;

class A{
    public:        
        void sayHello(){
            cout<<"Hello Love Babbar"<<endl;
        }

        void sayHello(string name){ // same function but diffrent declaration this is called polymorphism
            cout<<"Hello "<<name<<endl;
        }

        // int sayHello(){ -> function with only diffrent return type cannot be overloaded
        //     return 1; -> if you want to overload you have to give input as well
        // }
};

int main(){

    A obj;

    obj.sayHello();
    obj.sayHello("param");

    return 0;
}