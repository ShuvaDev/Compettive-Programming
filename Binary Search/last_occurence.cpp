#include<bits/stdc++.h>
using namespace std;

int last_occurence(vector<int> &vec, int target) {
    int L = 0, R = vec.size() - 1;

    while(L < R) {
        int M = L +  (R - L + 1) / 2;
        if(vec[M] > target) {
            R = M - 1;
        } else if(vec[M] < target) {
            L = M + 1;
        }else {
            L = M;
        }
    }
    return R;
}

int main() {
    vector<int> vec = {10, 10, 20, 30, 30, 30};
    cout << last_occurence(vec, 30);

}