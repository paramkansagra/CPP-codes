#include <iostream>

using namespace std;

class Animal{
    public:
        int age,weight;
    
    public:
        void speak(){
            cout<<"Speaking "<<endl;
        }
};

class Dog: public Animal{
    public:
        string breed;
    
    public:
        void bark(){
            cout<<"bhav bhav"<<endl;
        }
};

int main(){

    Dog d1;
    d1.speak();
    d1.bark();

    return 0;
}