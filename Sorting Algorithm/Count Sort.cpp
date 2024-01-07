#include<bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &vec) {
    int min = *min_element(vec.begin(), vec.end());
    int max = *max_element(vec.begin(), vec.end());

    int offset = (min < 0) ? (min * -1) : 0;

    min += offset, max += offset;

    vector<int> freq(max + 1, 0);

    for(int i = 0; i < vec.size(); i++) {
        vec[i] += offset;
    }

    for(auto i : vec) {
        freq[i]++;
    }
    int index = 0;
    for(int elem = min; elem <= max; elem++) {
        while(freq[elem]--) {
            vec[index++] = elem;
        }
    }
    for(int i = 0; i < vec.size(); i++) {
        vec[i] -= offset;
    }
    
}

int main() {
    vector<int> vec = {-5, 8, 2, -2, 4, 8};
    
    counting_sort(vec);

    for(auto i : vec) cout << i << " ";
    
    return 0;
}