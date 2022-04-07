#include <iostream>
#include "Classes_hero.cpp"

using namespace std;

int main(){

    // usual dynamic allocation
    //int * i = new int; // heap allocation of i

    // dynmaic allocation of object
    Hero* h = new Hero; // class_name * variable_name = new class_name;

    // getting and setting values using dynamic allocation

    h->setHealth(100); // also works with (*h).setHealth(100);
    h->setLevel('A');
    h->setName("Ramesh");

    // printing the values (WAY 1)
    cout<<"health of "<<(*h).getName()<<" is "<<(*h).getHeath()<<endl;
    cout<<"Level of "<<(*h).getName()<<" is "<<(*h).getLevel()<<endl;

    // printing the values (WAY 2)
    cout<<"health of "<<h->getName()<<" is "<<h->getHeath()<<endl;
    cout<<"level of "<<h->getName()<<" is "<<h->getLevel()<<endl;

    delete h;

    return 0;
}