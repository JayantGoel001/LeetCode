class Solution {
public:
    bool compare(vector<int> &vp,vector<int> &vs){
        bool flag = true;
        for(int i=0;i<26;i++){
            if(vp[i] != vs[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        
        for(auto it : p){
            vp[it - 'a']++;
        }
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(i >= p.size()){
                vs[s[i - p.size()] - 'a']--;
            }
            vs[s[i] - 'a']++;
            
            if(i + 1 >= p.size() && compare(vp, vs)){
                v.push_back(i + 1 - p.size());
            }
        }
        
        return v;
    }
};