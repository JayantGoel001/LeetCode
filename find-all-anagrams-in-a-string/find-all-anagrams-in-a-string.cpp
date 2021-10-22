class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> smp,pmp;
        
        vector<int> v;
        
        for(auto it : p){
            pmp[it]++;
        }
        
        int ss = s.size();
        int ps = p.size();
        
        for(int i=0;i<ss;i++){
            if(i >= ps){
                smp[s[i-ps]]--;
                if(smp[s[i-ps]] == 0){
                    smp.erase(s[i-ps]);
                }
            }
            smp[s[i]]++;
            
            if(smp == pmp){
                v.push_back(i - ps + 1);
            }
        }
        return v;
    }
};