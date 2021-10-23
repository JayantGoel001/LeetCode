class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        
        for(auto it : s){
            mp[it]++;
        }
        int count = 0;
        bool flag = false;
        for(auto it : mp){
            if(it.second%2 == 0){
                count += it.second;
            }else{
                count += (it.second-1);
                flag = true;
            }
        }
        if(flag){
            count++;
        }
        return count;
    }
};