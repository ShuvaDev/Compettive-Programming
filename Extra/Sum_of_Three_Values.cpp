#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    map<int, queue<int>> mp;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        mp[arr[i]].push(i + 1);
    }
    sort(arr.begin(), arr.end());

    int flag = 0;
    for(int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;

        while(l < r) {
            long long sum = arr[i] + arr[l] + arr[r];
            if(sum == x) {
                cout << mp[arr[i]].front() << " ";
                mp[arr[i]].pop();
                cout << mp[arr[l]].front() << " ";
                mp[arr[l]].pop();
                cout << mp[arr[r]].front() << "\n";
                mp[arr[r]].pop();
                flag = 1;
                return 0;
            } else if(sum > x) {
                r--;
            } else {
                l++;
            }
        }
    }

    if(flag == 0) printf("IMPOSSIBLE");
    
    return 0;
}