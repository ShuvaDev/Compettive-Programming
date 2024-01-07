#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

bool isPossible(vector<int> &vc, int x, long long height) {
    long long sum = 0;
    for(int i = 0; i < vc.size(); i++){
        if(vc[i] < height) {
            sum += height - vc[i];
        }
        if(sum > x) return false;
    }
    if(sum > x) {
        return false;
    } 
    return true;
} 

long long binary_search(vector<int> &vc, int x) {
    long long L = 1;
    long long R = LLONG_MAX / 4;


    while(L < R) {
        long long M = L + (R - L + 1) / 2;


        if(isPossible(vc, x, M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    return R;

}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x;
        scanf("%d %d", &n, &x);

        vector<int> vc(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &vc[i]);
        }
        cout << binary_search(vc, x) << endl;


    }
     
    
    
    return 0;
}