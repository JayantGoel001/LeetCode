class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                mp[nums2[st.top()]] = nums2[i] + 1;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<nums1.size();i++){
            nums1[i] = mp[nums1[i]] - 1;
        }
        return nums1;
    }
};