#include <bits/stdc++.h>

using namespace std;

int find(int x , vector<int>& representative){
    if(x == representative[x]) return x;

    return find(representative[x] , representative);
}

int find_with_path_compression(int x , vector<int>& representative){
    if(x == representative[x]) return x;

    // jab bhi ham call karenge to find the representative
    // we would find it change our own representative to be that one
    // so that next time when it is called time kam lage
    return representative[x] = find(representative[x] , representative);
}

void make_friends(vector<int>& representative , vector<int>& rank , int a , int b){
    int first_root = find(a , representative);
    int second_root = find(b , representative);

    if(first_root == second_root) return ;

    if(rank[first_root] < rank[second_root]){
        representative[first_root] = second_root;
    }
    else if(rank[first_root] > rank[second_root]){
        representative[second_root] = first_root;
    }
    else{
        representative[second_root] = first_root;
        rank[first_root]++;
    }
}

bool find_friends(vector<int>& representative , vector<int>& rank , int a , int b){
    int first = find(a , representative);
    int second = find(b , representative);

    if(first == second) return true;
    return false;
}

int main(){

    // the nodes would be in the range [1,n]
    int n;
    cout<<"input the number of nodes ";
    cin>>n;

    // we are making the representative array
    vector<int> representative(n + 1);
    vector<int> rank(n + 1 , 0);

    // initially for each node the own node is its representative
    for(int i=0;i<=n;i++){
        representative[i] = i;
    }

    // now we would do the functions
    int m;
    cout<<"input the number of operations ";
    cin>>m;

    while(m > 0){
        int operation;
        cout<<"1. make friends"<<endl;
        cout<<"2. find weather friends or not"<<endl;

        cout<<"input the operation ";
        cin>>operation;

        if(operation == 1 || operation == 2){

            if(operation = 1){
                int a , b;
                cout<<"input the numbers to make friends ";
                cin>>a>>b;

                if((a < 0 && a > n) || (b < 0 || b > n)){
                    cout<<"Wrong inputs"<<endl;
                }
                else{
                    make_friends(representative , rank , a , b);
                }
            }
            else{
                int a , b;
                cout<<"input the numbers to find friends ";
                cin>>a>>b;

                if((a < 0 && a > n) || (b < 0 || b > n)){
                    cout<<"Wrong inputs"<<endl;
                }
                else{
                    int ans = find_friends(representative , rank , a , b);
                    cout<<a<<" and "<<b<<" are ";
                    if(ans == 1) cout<<"friends"<<endl;
                    else cout<<"not friends"<<endl;
                }
            }

            m--;
        }
    }

    return 0;
}