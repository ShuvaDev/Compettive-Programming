#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

long long result[1];
void merge_them(int L, int R, vector<int> &arr) {
    int M = L + (R - L) / 2;

    int p = L, q = M + 1, ind = 0;

    vector<int> temp(R - L + 1);
    while(p <= M && q <= R) {
        if(arr[p] > arr[q]) {
            temp[ind++] = arr[q];
            q++;
            result[0] += (M - p + 1);
        } else {
            temp[ind++] = arr[p];
            p++;
        }
    }
    while(p <= M) {
        temp[ind++] = arr[p];
        p++;
    }
    while(q <= R) {
        temp[ind++] = arr[q];
        q++;
    }

    for(int i = 0; i < (R - L + 1); i++) {
        arr[L + i] = temp[i];
    }
}

void merge_sort(int L, int R, vector<int> &arr) {
    if(L == R) return;

    int M = L + (R - L) / 2;

    merge_sort(L, M, arr);
    merge_sort(M + 1, R, arr);

    merge_them(L, R, arr);
}

void merge_sort(vector<int> &arr) {
    merge_sort(0, arr.size() - 1, arr);
}

int main() {
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        result[0] = 0;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        merge_sort(arr);
        cout << result[0] << endl;
    }
    
    
    return 0;
}