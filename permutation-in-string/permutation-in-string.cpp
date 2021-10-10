class Solution {
public:
    bool cmp(int *mp,int *temp){
        for(int i=0;i<26;i++){
            if(mp[i] != temp[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string &s1, string &s2) {
        
        int k = s1.size();
        int size = s2.size();
        
        if(k > size){
            return false;
        }
        int mp[26],temp[26];
        for(int i=0;i<26;i++){
            mp[i] = 0;
            temp[i] = 0;
        }
        
        for(auto it : s1){
            mp[it - 'a']++;
        }
        int count = 0;
        
        for(int i=0;i<size;i++){
            temp[s2[i] - 'a']++;
            if(i >= k){
                temp[s2[i - k] - 'a']--;
            }
            if(cmp(mp,temp)){
                return true;
            }
        }
        return false;
    }
};