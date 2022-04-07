#include <iostream>
#include "Classes_hero.cpp"

using namespace std;

int main(){

    // static allocation of object
    Hero ramesh;// included from file classes_hero.cpp

    // to access properties(data members) of object "ramesh"
    // we can do that using dot operator

    ramesh.setHealth(70);
    ramesh.setLevel('A');
    ramesh.setName("Ramesh");

    cout<<"health of ramesh is "<<ramesh.getHeath()<<endl;
    cout<<"level of ramesh is "<<ramesh.getLevel()<<endl;
    cout<<"Name of ramesh is "<<ramesh.getName()<<endl;

    return 0;
}