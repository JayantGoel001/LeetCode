class Solution {
public:
    int countVowel(vector<int> &mp){
        return mp[0] + mp[4] + mp[8] + mp[14] + mp[20];
    }
    int maxVowels(string s, int k) {
        vector<int> v(26, 0);
        
        int maxi = 0;
        for(int i=0;i<s.size();i++){
            if(i >= k){
                v[s[i - k] - 'a']--;
            }
            v[s[i] - 'a']++;
            
            maxi = max(maxi, countVowel(v));
        }
        
        return maxi;
    }
};