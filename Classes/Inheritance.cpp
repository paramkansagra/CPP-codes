#include <iostream>

using namespace std;

// inheritance is nothing but inheriting some properties like variables and functions from another
// class just to reduce the code length and workload

// the class inheriting the properties is called sub class and the class giving the properties
// is called parent class

class Human{
    private:
        int height,weight,age;
    public:
        int getAge(){
            return this->age;
        }
        int getWeight(){
            return this->weight;
        }
        int getHeight(){
            return this->height;
        }

        void setAge(int age){
            this->age = age;
        }
        void setWeight(int weight){
            this->weight = weight;
        }
        void setHeight(int height){
            this->height = height;
        }
};

// child class
// class <name_of_class>: <mode> <name of parent class>{};

class Male: public Human{
    public:
        string color;

        void sleep(){
            cout<<"Male is sleeping"<<endl;
        }
}; 

int main(){

    Male object1;
    
    object1.setAge(18);
    object1.setWeight(80);
    object1.setHeight(170);
    object1.color = "brown";

    cout<<object1.getAge()<<" "<<object1.getHeight()<<" "<<object1.getWeight()<<" ";
    object1.sleep();

    return 0;
}