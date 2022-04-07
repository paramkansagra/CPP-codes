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

        // destructors
        ~Hero(){
            cout<<"Destructor called "<<endl;
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

    // destructor is nothing but freeing the memory created
    // by the object

    // destructor is automatically created

    Hero h1; // usual constructor and destructor called

    Hero* h2 = new Hero;

    // jo bhi objects are created using static allocation
    // uske lie automatically destructor is called
    // else you have to call is manually

    delete h2; // calling it for dynamically allocated h2

    return 0;
}