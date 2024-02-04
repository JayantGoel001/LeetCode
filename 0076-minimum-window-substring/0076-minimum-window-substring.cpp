class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it : t){
            mp[it]++;
        }
        int tsize = t.size();
        
        int start = 0;
        int i = 0;
        int mini = INT_MAX;
        
        int head = -1;
        
        while(i < s.size()){
            if(mp[s[i]] > 0){
                tsize--;
            }
            mp[s[i]]--;
            
            while(tsize == 0){
                if(i - start + 1 < mini){
                    mini = i - start + 1;
                    head = start;
                }
                if(mp[s[start]] == 0){
                    tsize++;
                }
                mp[s[start]]++;
                start++;
            }
            i++;
        }
        return mini == INT_MAX ? "" : s.substr(head,mini);
    }
};