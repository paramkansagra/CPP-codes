#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

string firstNonRepeatingCharacter(string s){
    string ans = ""; // making a ans string to return
    unordered_map<char,int> count; // making a map to count the number of occurances
    queue<int> q; // a queue is put in place to check which characters are coming in and going out

    for(int i=0;i<s.length();i++){
        char ch = s[i]; // taking the character ch for refrence
        count[ch]++; // first increase the count of ch
        q.push(ch); // and push it inside the queue

        while(!q.empty()){ // till the queue is not empty
            if(count[q.front()]>1){ // check if the first character is repeating or non repeating
                q.pop(); // if it is repeating then remove it 
            }
            else{
                ans.push_back(q.front()); // else push it inside the answer string and break
                break;
            }
        }

        if(q.empty()){ // now if the queue is empty so nothing is pushed inside the ans string
            ans.push_back('#'); // so we have to push the # and go ahead
        }
    }

    return ans; // return the ans string to the main function
}

int main(){

    string s; // making a input string s and taking the input
    cin>>s;

    string ans = firstNonRepeatingCharacter(s); // getting the answer string from the function
    cout<<ans<<endl; // print the answer string 

    return 0;
}