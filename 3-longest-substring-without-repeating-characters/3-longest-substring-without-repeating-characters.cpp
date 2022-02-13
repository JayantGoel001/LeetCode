class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        
        unordered_map<char,int> mp;
        int maxi = 0;
        int prev = 0;
        for(int i=0;i<s.size();i++){
            prev = max(prev,mp[s[i]]);
            maxi = max(maxi,i + 1 - prev);
            mp[s[i]] = i + 1;
        }
        return maxi;
    }
};