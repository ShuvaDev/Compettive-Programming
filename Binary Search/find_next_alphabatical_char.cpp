// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int getLowerBound(vector<char>& letters, char target) {
    int L = 0, R = letters.size();

    while(L < R) {
        int M = L + (R - L) / 2;
        if(letters[M] < target) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    return L;
}

int getUpperBound(vector<char> &letters, char target) {
    return getLowerBound(letters, target + 1);
}

char nextGreatestLetter(vector<char>& letters, char target) {
    int UB = getUpperBound(letters, target);
    if(UB == letters.size()) return letters[0];
    return letters[UB];
}

int main() {
    vector<char> letters = {'c', 'f', 'j'};

    cout << nextGreatestLetter(letters, 'a');
    
    
    
    return 0;
}