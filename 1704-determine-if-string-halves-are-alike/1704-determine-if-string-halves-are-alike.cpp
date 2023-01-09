class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0;i<s.size()/2;i++){
            count1 += (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U');
        }
        for(int i=s.size()/2;i<s.size();i++){
            count2 += (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U');
        }
        return count1 == count2;
    }
};