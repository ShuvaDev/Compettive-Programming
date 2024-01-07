#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        vector<int> arr[n];
        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);

            arr[i].resize(m);

            for(int j = 0; j < m; j++) {
                scanf("%d", &arr[i][j]);
            }
            sort(arr[i].begin(), arr[i].end());
        }

        long long sum = 0;
        // for(int i = n - 1; i > 0; i--) {
        //     sum += arr[i][1];
        //     arr[0].push_back(arr[i][0]);
        // }
        // sort(arr[0].begin(), arr[0].end());
        // sum += arr[0][0];

        int ind = 0, MIN = arr[0][1];
        for(int i = 1; i < n; i++) {
            if(arr[i][1] < MIN) {
                ind = i, MIN = arr[i][1];
            }
        }

        for(int i = 0; i < n; i++) {
            if(i != ind) {
                sum += arr[i][1];
                arr[ind].push_back(arr[i][0]);
            }
        }
        sort(arr[ind].begin(), arr[ind].end());


        sum += arr[ind][0];

        cout << sum << endl;
        
    }
     
    
    
    return 0;
}