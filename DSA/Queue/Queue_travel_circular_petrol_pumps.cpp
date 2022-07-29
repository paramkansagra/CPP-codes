#include <iostream>

using namespace std;

int tour(int petrol[],int distance[],int n){
    int deficit = 0;
    int start = 0;
    int balance = 0;

    for(int i=0;i<n;i++){
        balance += petrol[i] + distance[i];
        if(balance<0){
            deficit += balance;
            balance = 0;
            start = i+1;
        }
    }

    if(deficit+balance >= 0){
        return start;
    }
    else{
        return -1;
    }
}

int main(){

    int n;
    cin>>n;

    int petrol[n];
    int distance[n];

    for(int i=0;i<n;i++){
        cin>>petrol[i]>>distance[i];
    }

    int ans = tour(petrol,distance,n);
    cout<<ans<<endl;

    return 0;
}