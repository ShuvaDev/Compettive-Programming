#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    vector<int> vec = {1, -1, 0, 2, -2, 3};
      
    for(int i = 0; i < vec.size(); i++) {
        unordered_set<int> s;
        for(int j = i + 1; j < vec.size(); j++) {
            int x = -(vec[i] + vec[j]);

            if(s.count(x)) {
                cout << "( " << vec[i] << " " << vec[j] << " " << x << " )" << endl;
            } else {
                s.insert(vec[j]);
            }
        }
    }
    
    return 0;
}