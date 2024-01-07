#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    
    stack<int> st;
        map<int, int> mp;
        vector<int> result(nums1.size());
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if(st.empty()) {
                mp[nums2[i]] = -1; 
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        
        for(auto [f, s] : mp) cout << f << " " << s << endl;
        vector<int> result(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            result[i] = 
        }
    
    return 0;
}