#include <iostream>
#include <string.h>
using namespace std;

class Hero{
    private:
        int health;
        char level;

    public:
        char *name;

        Hero(){ // constructor
            cout<<"Simple Constructor Called"<<endl;
            name = new char[100];
        }

        Hero(int health){
            this -> health = health;
        }

        Hero(int health,char level){
            this->health = health;
            this->level = level;
        }

        // COPY CONSTRUCTORS
        // Hero(Hero& temp){
        //     this->health = temp.getHealth();
        //     this->level = temp.getLevel();
        // }

        // because we made our own constructor hear
        // the pre built one gets removed automatically


        int getHealth(){ // getter function
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

        void print(){
            cout<<endl;
            cout<<"Name "<<this->name<<endl;
            cout<<"health "<<this->health<<endl;
            cout<<"level "<<this->level<<endl;
            cout<<endl;
        }

        void setName(char name[]){
            strcpy(this->name,name);
        }
};

int main(){

    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');

    char name[6] = "Param";
    hero1.setName(name);

    hero1.print();

    // use default copy constructor // does a shallow copy
    Hero hero2(hero1);
    hero2.print();

    // it is similar to associate a object 2 with object 1
    // like connecting object 2 to object 1
    // if i want any thing of object 2 then i will access from object 1 and vice versa
    // dono ka sab kuch same rahega for all time

    // shallow copy => accessing the same memory with diffrent names
    hero2.name[0] = 'G';
    hero1.print(); // both of them are same
    hero2.print();

    // deep copy is nothing but to make a new memory address for object 2 with the same values of object 1

    return 0;
}