#include <stdio.h>

int main(){

    int n;
    printf("input the number of toys ");
    scanf("%d",&n);

    printf("input r for red b for blue g for gree p for pink and y for yellow \n");

    // now run the loop
    int red=0,blue=0,green=0,pink=0,yellow=0;
    for(int i=0;i<n;i++){
        char x;
        scanf(" %c",&x);
        if(x == 'r') red += 1;
        if(x == 'b') blue += 1;
        if(x == 'g') green += 1;
        if(x == 'p') pink += 1;
        if(x == 'y') yellow += 1;
    }

    printf("the number of balls in red bucket %d blue bucket %d green bucket %d pink bucket %d and yellow bucket %d",red,blue,green,pink,yellow);


    return 0;
}