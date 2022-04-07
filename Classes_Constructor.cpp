#include <iostream>

using namespace std;

class Hero{
    private:
        int health;
        char level;
        string name;

    public:
        Hero(){ // constructor
            cout<<"Constructor Called"<<endl;
        }

        // because we made our own constructor hear
        // the pre built one gets removed automatically

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

    // object created statically
    Hero h1; // when the object is created then the constructor is called

    // object created dynamically
    Hero* h = new Hero; // object is created so constructor is called

    // so object is called statically or dynamically
    // constructor is called



    return 0;
}