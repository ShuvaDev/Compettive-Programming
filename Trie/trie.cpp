#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        bool isEnd;
        TrieNode* next[26];
        int count;

        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }    
            count = 0;
        }
    
};

void insert(TrieNode *root, string str) {
        auto currNode = root;
    
        for(auto chr : str) {
            int id = chr - 'a';
            if(currNode -> next[id] == nullptr) {
                currNode -> next[id] = new TrieNode();
            }
            currNode = currNode -> next[id];
            currNode -> count ++;
        }
        currNode -> isEnd = true;
    }

bool search(TrieNode *root, string str) {
    auto currNode = root;

    for(auto chr : str) {
        int id = chr - 'a';

        if(currNode -> next[id] == nullptr) {
            return false;
        }
        currNode = currNode -> next[id];
    }

    return currNode -> isEnd;
}

int prefixCount(TrieNode *root, string str) {
    auto currNode = root;

    for(auto chr : str) {
        int id = chr - 'a';

        if(currNode -> next[id] == nullptr) {
            return 0;
        }
        currNode = currNode -> next[id];
    }
    return currNode->count;
}


int main() {
    TrieNode *root = new TrieNode();
    
    insert(root, "shuva");
    insert(root, "shiva");

    cout << prefixCount(root, "shuva");
    
    return 0;
}