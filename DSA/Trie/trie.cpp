#include <bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            isTerminal = true;

            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
        }
};

class Trie{
    private:
    TrieNode* root;

    void insertUtil(TrieNode* root , string word){
        // base case
        if(word.length() == 0){

            // if the length of the word is 0 meaning all the characters have been covered and the last node is the terminal node
            // so we will just mark this node as the terminal node and return the value
            root->isTerminal = true;
            return ;
        }

        // we have all the characters given in CAPS
        // so we will be finding the index of the current character
        int index = word[0] - 'A';

        TrieNode* child;

        // if that character is already present in the node
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        // else if the character is not present in the root node
        else{
            // we will make a new node
            child = new TrieNode(word[0]);

            root->children[index] = child;
        }

        // recursively call the function to get the work done
        insertUtil(child , word.substr(1));
    }

    bool searchUtil(TrieNode* root , string word){

        // base case
        // if the word has completed
        if(word.length() <= 0){
            // and if the node is a terminal node then we will return true
            if(root->isTerminal) return true;

            // else if the node is not a terminal node then we will return false
            return false;
        }

        // first we will find the index of the initial character
        int index = word[0] - 'A';

        // if at that index the root has a child i.e. not NULL
        if(root->children[index] != NULL){

            // then we will pick up that child and the remaining word and call the function recursively
            TrieNode* child = root->children[index];
            return searchUtil(child , word.substr(1));
        }

        // else if at the index there was no child present meaning the word is not present
        else{
            // so we will return false
            return false;
        }
    }

    void removeUtil(TrieNode* root , string word){
        if(word.length() <= 0){
            // set the root node's terminal as false
            // meaing this node would become a non terminal effectively saying the word doesnt exist

            root->isTerminal = false;

            return;
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        removeUtil(child , word.substr(1));
    }

    bool startsWithUtil(TrieNode* root , string word){
        if(word.length() <= 0) return true;

        int index = word[0] - 'a';

        if(root->children[index] != NULL){
            return startsWithUtil(root->children[index] , word.substr(1));
        }
        else{
            return false;
        }
    }

    public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertWord(string word){
        insertUtil(root , word);
    }

    void removeWord(string word){
        removeUtil(root , word);
    }

    bool searchWord(string word){
        return searchUtil(root , word);
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root , prefix);
    }
};

int main(){

    Trie *t = new Trie();

    t->insertWord("Aritrika");
    t->insertWord("Param");
    t->insertWord("Dheeraj");
    t->insertWord("Ashmit");

    cout<<"Present or not"<<endl;
    if(t->searchWord("Dheeraj")){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    t->removeWord("Dheeraj");

    cout<<"Present or not"<<endl;
    if(t->searchWord("Dheeraj")){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}