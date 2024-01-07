#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;

    vector<int> vec(n);

    for(int i = 0; i < n; i++) cin >> vec[i];

    for(int i = 1; i < n; i++) {
        if(vec[i - 1] > vec[i]) {
            sum += vec[i - 1] - vec[i];
            vec[i] = vec[i - 1];
        }
    }    

    cout << sum;
    
    
    
    return 0;
}