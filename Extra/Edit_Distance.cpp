#include<bits/stdc++.h>
#define endl "\n"
#define sp " "
 
using namespace std;
 
int dp[5001][5001];
 
string s, t;
int findDistance(int ps, int pt) {
    if(ps >= s.size() || pt >= t.size()) {
        return max(s.size() - ps, t.size() - pt);
    }
    int &ret = dp[ps][pt];
 
    if(ret != -1) return ret;
 
 
    if(s[ps] == t[pt]) {
        ret = findDistance(ps + 1, pt + 1);
    } else {
        ret = min({
            1 + findDistance(ps + 1, pt + 1),
            1 + findDistance(ps + 1, pt),
            1 + findDistance(ps, pt + 1)
        });
    }
    return ret;
}
 
int main() {
    cin >> s >> t;
 
    for(int i = 0; i <= s.size(); i++) {
        for(int j = 0; j <= t.size(); j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << findDistance(0, 0);
    
    return 0;
}