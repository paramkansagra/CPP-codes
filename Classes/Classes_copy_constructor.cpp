#include <iostream>
#include <string.h>
using namespace std;

class Hero{
    private:
        int health;
        char level;
        char name[100];

    public:
        Hero(){ // constructor
            cout<<"Simple Constructor Called"<<endl;
        }

        Hero(int health){
            this -> health = health;
        }

        Hero(int health,char level){
            this->health = health;
            this->level = level;
        }

        // COPY CONSTRUCTORS
        Hero(Hero& temp){
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
            cout<<"health "<<this->health<<endl;
            cout<<"level "<<this->level<<endl;
        }

        void setName(char name[]){
            strcpy(this->name,name);
        }
};

int main(){

    Hero suresh(70,'C'); // making a object called suresh with health => 70 and level C
    
    // calling copy constructor
    Hero ritesh(suresh); // all data members are copied

    // making a object where
    // ritesh.health = suresh.health
    // ritesh.level = suresh.level

    suresh.print();
    ritesh.print();

    return 0;
}