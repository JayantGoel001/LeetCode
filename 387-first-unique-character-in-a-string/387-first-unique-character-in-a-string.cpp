class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        
        for(auto it : s){
            mp[it]++;
        }
        int size = s.size();
        for(int i=0;i<size;i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};