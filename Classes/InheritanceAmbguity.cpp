#include <iostream>

using namespace std;

class A{
    public:
        int x;
        void func(){
            cout<<x<<endl;
        }
};

class B{
    public:
        int y;
        void func(){
            cout<<y<<endl;
        }
};

class C: public B,public A{
    public:
};

int main(){

    C obj;
    obj.A::func(); // -> :: ambiguity operator so its way is <className>::<FunctionYouWantToCall>

    return 0;
}