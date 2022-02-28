class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int i = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        int maxi = 0;
        int maxLen = 0;
        while(i < n){
            mp[s[i]]++;
            maxi = max(maxi,mp[s[i]]);
            while(i - start >= maxi + k){
                mp[s[start]]--;
                start++;
            }
        
            maxLen = max(maxLen,i - start + 1);
            i++;
        }
        return maxLen;
    }
};