#include <string>

using namespace std;

class Hero{
    private:
        int health;
        char level;
        string name;

    public:
        int getHeath(){ // getter function
            return health;
        }

        char getLevel(){
            return level;
        }

        string getName(){
            return name;
        }

        void setHealth(int h){ // setter function
            health = h;
        }

        void setLevel(char ch){
            level = ch;
        }

        void setName(string n){
            name = n;
        }
};

/* 

access modifiers => public, private, protected

based on where we can access the properties or data members of the class we use access modifiers there

by default access modifier is PRIVATE

PUBLIC => the data members under this can be access anywhere in the class or object 

PRIVATE => the data members uder this can be accessed only in the class
            like koi bhi function hai then we can access the variables under the private

PROTECTED => we will learn this during child classes


IF the variable is private and we need to access it we use getter and setter

getter and setter is nothing but a function inside a class where we can get and set
    values of particular variables that are not accessible (because they are set private)

getter => fetch
setter => can be used to set values and give conditions

Agar Size of the object is not equal to the one calculated it is due to padding and greedy alignment
    Padding is nothing but to add 1 or more empty bits in the middle to align the data stucture in 
        the memory
    
    Greedy alignment => https://www.geeksforgeeks.org/data-structure-alignment/

*/