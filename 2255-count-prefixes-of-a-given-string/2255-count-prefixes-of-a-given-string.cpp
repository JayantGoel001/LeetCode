class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int> mp;
        for(auto it : words){
            mp[it]++;
        }
        string str = "";
        int count = 0;
        for(int i=0;i<s.size();i++){
            str += s[i];
            count += mp[str];
        }
        return count;
    }
};