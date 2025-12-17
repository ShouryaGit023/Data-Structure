#include <bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    TrieNode* children[26];
    int childCount;
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
    childCount=0;
};


class Trie {
private:
    TrieNode* root;

    // helper: check if node has any child
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i] != nullptr)
                return true;
        return false;
    }

    // helper: delete word recursively
    bool deleteUtil(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // reached end of word
        if (depth == word.length()) {
            if (!node->isEnd)
                return false;   // word not present

            node->isEnd = false;

            // if node has no children, it can be deleted
            return !hasChildren(node);
        }

        int idx = word[depth] - 'a';
        TrieNode* child = node->children[idx];

        if (!child)
            return false; // word not present

        bool shouldDeleteChild = deleteUtil(child, word, depth + 1);

        if (shouldDeleteChild) {
            delete child;
            node->children[idx] = nullptr;

            // current node can be deleted if it’s not end of another word
            return !node->isEnd && !hasChildren(node);
        }

        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // INSERT
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]){
                node->children[idx] = new TrieNode();
                root->childCount++;
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // SEARCH (full word)
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // STARTS WITH (prefix)
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }

    // DELETE word
    void remove(const string& word) {
        deleteUtil(root, word, 0);
    }
    // Q1. Longest Common Prefix
    string longestCommonPrefix(vector<string> &s,int n){
    
        Trie t;
        //insert all the string of vectors
        for(int i=0;i<n;i++){
            t.insert(s[i]);
        }
        string f=s[0];
        string ans="";
    
        for(int i=0;i<f.size();i++){
            char c=f[i];
    
            if(root->childCount==1){
                ans.push_back(c);

                //aage bdho
                int id=c-'a';
                root=root->children[id];

            }
            else{
                break;
            }
            if(root->isEnd){
                break;
            }
        }
        return ans;
    
    };
};

//--------------------------------------------------------------



  


int main(){
    Trie t;
    vector<string> s={"abs", "absent", "abscia"};
    t.longestCommonPrefix(s,3);

}