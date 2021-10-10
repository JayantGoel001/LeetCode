class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        unordered_map<char,int> mp,temp;
        
        for(auto it : s1){
            mp[it]++;
        }
        int count = 0;
        
        int k = s1.size();
        int size = s2.size();
        
        for(int i=0;i<size;i++){
            temp[s2[i]]++;
            if(i >= k){
                temp[s2[i - k]]--;
                
                if(temp[s2[i - k]] == 0){
                    temp.erase(s2[i - k]);
                }
            }
            if(mp == temp){
                return true;
            }
        }
        return false;
    }
};