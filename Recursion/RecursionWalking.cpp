#include <bits/stdc++.h>

using namespace std;

void walkingHome(int source,int dest){

    // base case
    if(source == dest){
        cout<<"pohuch gaya "<<endl;
        return ;
    }

    // recursive call
    source++;
    walkingHome(source,dest);
}

int main(){

    int source = 0;
    int dest = 10;

    walkingHome(source,dest);
    cout<<pow(10,9)+7<<endl;
    return 0;
}