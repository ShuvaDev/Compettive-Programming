#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {4, 4, 2, 3, 3, 2};


    int count = 0, target = 6;
    map<int, int> freq;

    for(int i = 0; i < vec.size(); i++) {
        int need = target - vec[i];
        count += freq[need];
        freq[vec[i]]++;
    }

    cout << count;
    return 0;
}