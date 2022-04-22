#include <bits/stdc++.h>

using namespace std;

void printCharArray(char ch[],int n){
    for(int i=0;i<n;i++){
        cout<<ch[i];
    }cout<<endl;
}

int getLength(char name[]){
    int count = 0;
    for(int i=0;name[i] != '\0';i++){
        count ++;
    }
    return count;
}

int main(){
    // defining a character variable
    char a = 'p'; // here a will have the char p assigned to it

    // but if we have to store a sentence or a word how will we do it?
    // here comes into play the strings

    // in cpp strings are nothing but char arrays (1d)
    int n;
    cout<<"enter n ";
    cin>>n;

    char ch[n]; // making a char array of lenght 10
    cout<<"enter string of length n ";
    cin>>ch; //taking input of the char array
    printCharArray(ch,n); // printing char array

    // when we use cin>>ch the array is stored then a 
    // null character /o is taken to show termination of the
    // string

    // when you give a space or a tab or a new line char
    // cin will stop execution

    char name[20];
    cout<<"Enter your name";
    cin>>name;

    cout<<"Your name is "<<name<<endl;
    cout<<getLength(name)<<endl;
    
    cout<<strlen(name)<<endl;

    // lets compare some strings
    char string1[n],string2[n];
    cout<<"enter string 1 of length n "<<endl;
    cin>>string1;
    cout<<"enter string 2 of length n "<<endl;
    cin>>string2;

    cout<<strcmp(string1,string2)<<endl;

    // lets copy some strings

    char string3[n];
    // strcpy(dest,origin);
    strcpy(string3,string2);

    
    return 0;
}