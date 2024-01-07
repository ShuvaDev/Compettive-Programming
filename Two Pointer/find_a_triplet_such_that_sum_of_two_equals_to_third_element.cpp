#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    vector<int> vec = {5, 32, 1, 7, 10, 50, 19, 21, 2};
    sort(vec.rbegin(), vec.rend());
    
    for(int i = 0; i < vec.size(); i++) {
        int x = vec[i];
        int l = i + 1, r = vec.size() - 1;

        while(l < r) {
            int sum = vec[l] + vec[r];
            if(sum == x) {
                cout << x << sp << vec[l] << sp << vec[r] << endl;
            }
            if(sum < x) r--;
            else l++;
        }
    }
    
    
    
    return 0;
}

/*
    - 1 2 3 => size = 4
*/