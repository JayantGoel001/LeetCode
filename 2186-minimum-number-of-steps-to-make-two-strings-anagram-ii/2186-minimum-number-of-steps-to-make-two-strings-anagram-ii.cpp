class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto it : t){
            mp[it]--;
        }
        int count = 0;
        for(auto it : mp){
            count += abs(it.second);
        }
        return count;
    }
};