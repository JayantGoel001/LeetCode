class Solution {
public:
    int countSegments(string s) {
        
        s.push_back(' ');
        int count = 0;
        for(int i=1;i<s.size();i++){
            count += (s[i] == ' ' && s[i - 1] != ' ');
        }
        return count;
    }
};