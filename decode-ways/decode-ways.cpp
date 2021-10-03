class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int prev = 1;
        int prevP = 1;
        
        int size = s.size();
        for(int i=1;i<size;i++){
            int temp = 0;
            
            if(s[i]>'0' && s[i] <= '9'){
                temp += prev;
            }
            int number = (s[i-1]-'0') * 10 + (s[i] - '0');
        
            if(number >=10 && number <= 26){
                temp += prevP;
            }
            prevP = prev;
            prev = temp;
        }
        return prev;
    }
};