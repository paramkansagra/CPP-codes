#include <iostream>
#include <vector>

using namespace std;

class A{
    public:
        int sum(int a,int b){
            return a+b;
        }
        int sum(int a,int b,int c){
            return a+b+c;
        }
        int sum(vector<int> arr){
            int total = 0;
            for(int i=0;i<arr.size();i++){
                total += arr[i];
            }
            return total;
        }
};

int main(){

    A obj;
    cout<<obj.sum(10,20)<<endl;
    cout<<obj.sum(10,20,30)<<endl;

    return 0;
}