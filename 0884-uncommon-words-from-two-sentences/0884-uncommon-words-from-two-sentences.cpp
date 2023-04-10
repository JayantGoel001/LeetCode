class Solution {
public:
    unordered_map<string,int> getWords(string str){
        unordered_map<string,int> mp;
        string s = "";
        for(auto it : str){
            if(it == ' '){
                mp[s]++;
                s = "";
            }else{
                s += it;
            }
        }
        mp[s]++;
        
        return mp;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> st1 = getWords(s1);
        unordered_map<string,int> st2 = getWords(s2);
        
        vector<string> v;
        for(auto it : st1){
            if(it.second == 1 && st2[it.first] == 0){
                v.push_back(it.first);
            }
        }
        for(auto it : st2){
            if(it.second == 1 && st1[it.first] == 0){
                v.push_back(it.first);
            }
        }
        return v;
    }
};