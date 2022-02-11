class Solution {
public:
    bool checkPermutation(unordered_map<char,int> &mp){
        for(auto it : mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        
        if(size1 > size2){
            return false;
        }
        
        unordered_map<char,int> mp;
        
        for(auto it : s1){
            mp[it]++;
        }
        for(int i=0;i<size1;i++){
            mp[s2[i]]--;
        }
        if(checkPermutation(mp)){
            return true;
        }
        for(int i=size1;i<size2;i++){
            mp[s2[i]]--;
            mp[s2[i - size1]]++;
            if(checkPermutation(mp)){
                return true;
            }
        }
        return false;
    }
};