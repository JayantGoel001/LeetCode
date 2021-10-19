class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(auto it : nums2){
            while(!st.empty() && st.top()<it){
                mp[st.top()] = it;
                st.pop();
            }
            st.push(it);
        }
        vector<int> v;
        for(auto it : nums1){
            if(mp[it] == 0){
                mp[it]=-1;
            }
            v.push_back(mp[it]);
        }
        return v;
    }
};