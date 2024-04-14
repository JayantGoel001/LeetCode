class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum+=abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
        }
        return sum;
    }
};