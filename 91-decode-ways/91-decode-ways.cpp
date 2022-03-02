class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int prev = 1;
        int prevPrev = 1;
        
        for(int i=1;i<s.size();i++){
            int temp = 0;
            
            if(s[i] > '0' && s[i] <= '9'){
                temp += prev;
            }
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(num >= 10 && num <= 26){
                temp += prevPrev;
            }
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};