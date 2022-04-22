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

class Dog{
    public:
        string breed;
    
    public:
        void bark(){
            cout<<"bhav bhav"<<endl;
        }
};

// just add a comma XD 

class GermanShephard: public Dog,public Animal{
    public:
        void fetch(){
            cout<<"Running...Ball Fetched"<<endl;
        }
};

int main(){

    GermanShephard d1;
    d1.speak();
    d1.bark();
    d1.fetch();

    return 0;
}