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

        //COPY CONSTRUCTORS
        Hero(Hero& temp){

            // making a deep copy
            char *ch = new char[strlen(temp.name)+1]; 
            strcpy(ch,temp.name);
            this-> name = ch;
            
            this->health = temp.getHealth();
            this->level = temp.getLevel();
        }

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

    // using our own defined constructor
    // so makes a deep copy
    Hero hero2(hero1);

    // shallow copy => accessing the same memory with diffrent names
    // deep copy is nothing but to make a new memory address for object 2 with the same values of object 1
    hero2.name[0] = 'G';
    
    hero1.print();
    hero2.print();

    hero1 = hero2;
    
    hero1.print();
    hero2.print();


    return 0;
}