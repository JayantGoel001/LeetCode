class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int maxi = 0;
        unordered_map<char,int> mp;
        
        int size = s.size();
        int prev = 0;
        for(int i = 0;i<size;i++){
            prev = max(prev,mp[s[i]]);
            maxi = max(maxi,i+1 - prev);
            mp[s[i]] = i + 1;
        }
        return maxi;
    }
};