#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &vec) {
    // Complexity : O(NK) [K = number of elements which are not in right index]
    for(int i = 1; i < vec.size(); i++) {
        int j = i - 1;
        int key = vec[i];

        while(key < vec[j] && j >= 0) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main() {
    vector<int> vec = {-5, 8, 2, -8, 10, 12, 6, 1};
    
    insertion_sort(vec);

    for(auto i : vec) cout << i << " ";
    
    return 0;
} 