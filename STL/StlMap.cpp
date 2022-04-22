#include <bits/stdc++.h>

using namespace std;

// in the map function the data is stored in a key value
// form it is similar to dict in python

// all the key are unique and the key only points to 1 value
// if multiple values are given then the last element taken 
// as the key value pair we can say it gets updated

// implementation done using red black tree or a balnced tree

// implementation of a unordered map is done using a hash table
// there the time complexity of finding the element is O(1)

void printMap(map<int,string> m){

    // here i is the iterator and using the key value pair
    // first and second we can print the elements of the map

    // here first is the key and second is the value

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}

int main(){

    map<int,string> m;

    // pushing elements into the map or dict

    m[1] = "param";
    m[2] = "kansagra";
    m[3] = "c++";

    // in a map everything is in a sorted order

    printMap(m);

    // for a unordered map it becomes unordered but its a 
    // bit faster

    // other way of inserting elements in a map
    // syntax map_var.insert({key,value});
    m.insert({4,"good"});
    m.insert({5,"way of learning cpp"});

    printMap(m);

    // using the count we can find if the key is present
    // or not

    cout<<"is 5 present in the map "<<m.count(5)<<endl;
    cout<<"is 10 present in the map "<<m.count(10)<<endl;
    cout<<endl;
    // before erase

    printMap(m);

    // after erase;
    // using the erase function we can remove the elements
    // from a map
    // syntax mapVar.erase(keyValue); O(log n)
    m.erase(1);
    printMap(m);

    // now we can do find
    // find returns the iterator of that element

    auto itr = m.find(3);

    // printing the value present at this iterator

    for(auto i=itr;i!=m.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }

    return 0;
}