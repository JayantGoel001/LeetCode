class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        int count = 0;
        bool hasOdd = false;
        for(auto it : mp){
            count += (it.second%2 == 0 ? it.second : it.second-1);
            if(it.second % 2 == 1 && !hasOdd){
                hasOdd = true;
            }
        }
        return count + hasOdd;
    }
};