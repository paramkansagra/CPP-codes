#include<iostream>
 
using namespace std;
 
class Animal{
    public:
        void speak(){
            cout<<"Speaking"<<endl;
        }
};

class Dog: public Animal{
    public:
        void speak(){
            cout<<"Barking"<<endl;
        }
};

int main(){

    Dog obj;
    obj.speak(); // -> dog ka speaking aya even if there is a speak function in the parent class

    return 0;
}