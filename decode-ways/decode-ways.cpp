class Solution {
public:
    int numDecodings(string &str){
        if(str[0] == '0'){
            return 0;
        }
        int prev = 1;
        int prevPrev = 1;
        
        int size = str.size();
        for(int i=1;i<size;i++){
            int temp = 0;
            
            if(str[i] > '0' && str[i] <= '9'){
                temp += prev;
            }
            int num = (str[i-1] - '0') * 10 + (str[i] - '0');
            if(num >= 10 && num <=26){
                temp += prevPrev;
            }
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};