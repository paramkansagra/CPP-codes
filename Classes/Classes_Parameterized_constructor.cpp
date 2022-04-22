#include <iostream>

using namespace std;

class Hero{
    private:
        int health;
        char level;
        string name;

    public:
        Hero(int health){ // constructor
            cout<<"this -> "<<this<<endl;
            this -> health = health;
        }
        // now if we see health is declare in the constructor as well as in the private class
        // now if we do health = health;
        // then we are putting health's value into itself -> which is not we want
        // here we use "this"  keyword

        // this keyword is nothing but a pointer pointing to the current object
        // eg:- ramesh is a object then "this" pointer will be pointing to ramesh's address

        // using pointers then we can give the value to private integers of the class

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

int main(){

    Hero ramesh(100); // because parameterized constructor
    cout<<"address of ramesh is "<<&ramesh<<endl;

    return 0;
}