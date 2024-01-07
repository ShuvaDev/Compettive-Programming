#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

const int MAX_N = 1e5 + 5;
vector<bool> p(MAX_N);
vector<int> primes;

void sieve() {
    p[1] = 1;
    for(int i = 2; i * i <= MAX_N; i++) {
        if(p[i] == 0) {
            for(int j = i * i; j <= MAX_N; j += i) {
                p[j] = 1;
            }
        }
    }
    for(int i = 2; i < MAX_N; i++) {
        if(p[i] == 0) {
            primes.push_back(i);
        }
    }
}


int main() {
    sieve();
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        map<int, bool> visit;

        vector<int> result(n);
        result[0] = 1;
        int ind = 1;
        for(auto p : primes) {
            if(p > n) {
                break;
            }

            for(int i = p; i <= n; i += i) {
                result[ind] = i;
                visit[i] = 1;
                ind++;
            }
        }
        for(int i = 2; i <= n; i++) {
            if(visit[i] != 1) {
                for(int j = i; j <= n && visit[j] != 1; j += j) {
                    result[ind] = j;
                    visit[j] = 1;
                    ind++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }    
    
    
    
    return 0;
}

// 1 11 13 15 17 2 4 8 16 3 6 12 5 10 7 14 9 18 
// 1  2 4 8  3 6  5  7   9 
// 1 2 4 8 16 3 6 12 5 10 7 14 11 13 17 9 18 15
// 1 2 4 8  3 6  5  7 9 