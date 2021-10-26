class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int size = s.size();
        for(int i=0;i<size-2;i++){
            if(s[i] != s[i+1] && s[i+1]!=s[i+2] && s[i+2]!=s[i]){
                count++;
            }
        }
        return count;
    }
};