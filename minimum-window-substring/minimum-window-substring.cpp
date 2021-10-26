class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmp;
        for(auto it : t){
            tmp[it]++;
        }
        int ts = t.size();
        
        int i = 0;
        int j = 0;
        int size = s.size();
        int d = INT_MAX;
        int head = 0;
        
        while(j < size){
            if(tmp[s[j]] > 0){
                ts--;
            }
            tmp[s[j]]--;
            while(ts == 0){
                if(j + 1 - i < d){
                    d = j + 1 - i;
                    head = i;
                }
                if(tmp[s[i]] == 0){
                    ts++;
                }
                tmp[s[i]]++;
                i++;
            }
            j++;
        }
        return d == INT_MAX ? "" : s.substr(head,d);
    }
};