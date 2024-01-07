#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80};
    int x = 200;
    for(int i = 0; i < vec.size(); i++) {
        for(int j = i+1; j < vec.size(); j++) {
            int l = j + 1;
            int r = vec.size() - 1;

            while(l < r) {
                int sum = vec[i] + vec[j] + vec[l] + vec[r];

                if(sum == x) {
                    cout << vec[i] << " " << vec[j] << " " << vec[l] << " " << vec[r] << endl;
                }

                if(sum > x) r--;
                else l++;
            }
        }
    }
    
    
    
    return 0;
}