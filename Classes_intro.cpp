#include <iostream>

using namespace std;

// as we have int x char ch and string s
// here int char and string are data types

// so classes are user defined data types

class Hero{ // this is a class named hero

    // properties of the class named hero
    char name[100];
    int health;
    char level;
};

// so we made a user defined data type called hero 
// now we will make a object called paul

int main(){

    int x; // hear we made a object of class int called x

    Hero paul; // made a object of class hero called paul
    cout<<sizeof(paul)<<endl; // 108 => 100 bytes of char and 4 bytes of health and level 

    // so size taken by the object is equal to the size of the properties held by it

    // so class is kind of a template
    // and the variables like paul and all are instances of the class

    // example int template ka 2 variable hai x and y
    // so x and y are the instances of the class int
    // and they will have attributes same as that defined in int
    // like value address size and all

    // if there is a empty class
    // what is the memory allocation? => 1 byte just for identification

    return 0;
}