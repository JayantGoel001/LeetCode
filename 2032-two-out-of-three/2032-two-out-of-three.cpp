class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st3(nums3.begin(), nums3.end());
        
        unordered_set<int> st;
        for(auto it : nums1){
            if(st2.find(it) != st2.end() || st3.find(it) != st3.end()){
                st.insert(it);
            }
        }
        for(auto it : nums2){
            if(st1.find(it) != st1.end() || st3.find(it) != st3.end()){
                st.insert(it);
            }
        }
        for(auto it : nums3){
            if(st2.find(it) != st2.end() || st1.find(it) != st1.end()){
                st.insert(it);
            }
        }
        vector<int> v(st.begin(),st.end());
    
        return v;
    }
};