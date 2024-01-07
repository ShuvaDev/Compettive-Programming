#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    int x = 100;

    /*
    for(int i = 0; i < vec.size(); i++) {
        unordered_set<int> s;
        for(int j = i+1; j < vec.size(); j++) {
            int sum = vec[i] + vec[j];

            if(s.count(x - sum)) {
                cout << vec[i] << sp << vec[j] << sp << x - sum << endl;
            } else {
                s.insert(vec[j]);
            }
        }
    }
    */

   for(int i = 0; i < vec.size(); i++) {
        int l = i+1;
        int r = vec.size() - 1;
        
        while(l < r) {
            int sum = vec[i] + vec[l] + vec[r];
            if(sum == x) {
                cout << vec[i] << sp << vec[l] << sp << vec[r] << endl;
            } 
            if(sum > x) r--;
            else l++;
        }
   }
    
    
    return 0;
}