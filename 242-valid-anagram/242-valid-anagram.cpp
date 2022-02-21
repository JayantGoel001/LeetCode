class Solution {
public:
    bool isAnagram(string s, string t) {
        int ar[26]={0};
        for(auto it : s){
            ar[it-'a']++;
        }
        for(auto it : t){
            ar[it-'a']--;
        }
        bool res = true;
        for(int i=0;i<26;i++){
            res &= !ar[i];
        }
        return res;
    }
};