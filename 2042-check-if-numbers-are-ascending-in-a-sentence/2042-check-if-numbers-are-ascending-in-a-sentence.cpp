class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int i = 0;
        while(i < s.size()){
            int num = 0;
            
            while(i < s.size() && (s[i] < '0' || s[i] > '9')){
                i++;
            }
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if(num != 0 && num <= prev){
                return false;
            }
            prev = num;
            i++;
        }
        return true;
    }
};