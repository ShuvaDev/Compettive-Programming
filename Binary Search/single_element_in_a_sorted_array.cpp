// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int L = 0, R = nums.size() - 1; 

        while(L <= R) {
            int M = L + (R - L) / 2;

            if(M == 0 && nums[M] != nums[M+1]) return nums[M];
            else if(M == nums.size() - 1 && nums[M] == nums[M-1]) return nums[M];
            else if(nums[M] != nums[M-1] && nums[M] != nums[M+1]) return nums[M];
            else {
                if(nums[M] == nums[M+1]) {
                    if(M % 2) R = M; 
                    else L = M + 2;
                } else if(nums[M] == nums[M - 1]) {
                    if((M - 1) % 2) R = M - 1;
                    else L = M + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s1;
    vector<int> arr = {1, 2, 2};
    cout << s1.singleNonDuplicate(arr);
    
    
    
    return 0;
}

