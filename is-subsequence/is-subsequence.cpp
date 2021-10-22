class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int ss = s.size();
        int j = 0;
        int ts = t.size();
        
        while(i < ss && j < ts){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == ss;
    }
};