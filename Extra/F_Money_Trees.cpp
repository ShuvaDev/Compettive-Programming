#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

vector<int> fruit, height;
vector<pair<pair<int, int>, int>> subArray;

void generateValidSubArray(int n) {
    subArray.clear();

    int st = 0, sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += fruit[i];
        if(height[i] < height[i+1]) {
            subArray.push_back({{st, i}, sum});
            st = i + 1;
            sum = 0;
        } else {
            if(height[i] % height[i + 1] != 0) {
                subArray.push_back({{st, i}, sum});
                st = i + 1;
                sum = 0;
            }
        }
    }
    sum += fruit[n - 1];
    subArray.push_back({{st, n - 1}, sum});
}

int getMaxLength(int n, int k) {
    int res = 0;
    for(auto &[p, sum] : subArray) {
        
        int i = p.first, j = p.first;
        int S = 0;
        while (j <= p.second)
        {
            S += fruit[j];
            if(S <= k){
                res = max(res,j-i+1);
                j++;
                continue;
            }else{
                res = max(res,j-i);
                S -= fruit[i];
                i++;
            }

            j++;
        }
    }
    return res;


}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        fruit.clear();
        height.clear();
        fruit.resize(n);
        height.resize(n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &fruit[i]);
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &height[i]);
        }

        generateValidSubArray(n);

        
        cout << getMaxLength(n, k) << endl;
      
    }
    
    
    
    return 0;
}