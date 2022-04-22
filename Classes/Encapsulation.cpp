#include <iostream>

using namespace std;

// encapsulation is nothing but wrapping up some functions and variables in a capsule
// the capsule is a class -> here you wrap up diffrent functions and variables in a class capsule

// Fully encapsulated class -> all data members are private
// advantage -> information hiding (not thinking getter and setter)
//           -> we can set the class to read only
//           -> code reuseablility and code testing

class Student{
    private:
        string name;
        int age;
        int height;
    
    public:
        int getAge(){
            return this->age;
        }
        int getHeight(){
            return this->height;
        }
        string getName(){
            return this->name;
        }
};

int main(){

    Student s1;

    return 0;
}