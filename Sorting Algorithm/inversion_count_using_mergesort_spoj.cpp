// https://vjudge.net/problem/SPOJ-INVCNT

#include<bits/stdc++.h>
using namespace std;

long long inv_count = 0;
void merge_them(vector<int> &vc, int L, int R) {
    int M = L + (R - L) / 2;

    int p1 = L, p2 = M + 1;

    vector<int> temp(R - L + 1);

    int ind = 0;
    long long temp_count = 0;

    while(p1 <= M && p2 <= R) {
        if(vc[p1] > vc[p2]) {
            temp_count++;
            temp[ind++] = vc[p2];
            // cout << temp_count << endl;
            p2++;
        } else {
            inv_count += (M - p1 + 1) * temp_count;
            temp_count = 0;
            temp[ind++] = vc[p1];
            p1++;
        }
    }

    while(p1 <= M) {
        inv_count += temp_count;
        temp[ind++] = vc[p1];
        p1++;
    }
    while(p2 <= R) {
        temp[ind++] = vc[p2];
        p2++;
    }

    for(int i = 0; i < temp.size(); i++) {
        vc[L++] = temp[i];
    }
}

void merge_sort(vector<int> &vc, int L, int R) {
    if(L >= R) return;

    int M = L + (R - L) / 2;

    merge_sort(vc, L, M);
    merge_sort(vc, M + 1, R);

    merge_them(vc, L, R);
}

void merge_sort(vector<int> &vc) {
    merge_sort(vc, 0, vc.size() - 1);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> vc(n);
        for(int i = 0; i < n; i++) {
            cin >> vc[i];
        }

        inv_count = 0;
        merge_sort(vc);

        cout << inv_count << endl;

    }
    
    return 0;
}