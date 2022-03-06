class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }
        
        auto cmp = [&](string word1,string word2)-> bool{
            int n = word1.size();
            int m = word2.size();
            for(int i = 0;i<min(n,m);i++){
                if(word1[i] != word2[i]){
                    return mp[word1[i]] < mp[word2[i]];
                }
            }
            return n <= m;
        };
        
        for(int i=0;i<words.size()-1;i++){
            if(!cmp(words[i],words[i+1])){
                return false;
            }
        }
        return true;
    }
};