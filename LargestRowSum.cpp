#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cout<<"input row and col ";
    cin>>n>>m;

    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int maxi = -1;
    int row = 0;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<m;j++){
            count += arr[i][j];
        }
        if(count<maxi){
            maxi = count;
            row = i;
        }
    }

    cout<<maxi<<" "<<row<<endl;

    return 0;
}