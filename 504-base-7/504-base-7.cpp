class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string str = "";
        bool neg = false;
        if(num < 0){
            num *= -1;
            neg = true;
        }
        while(num){
            str = (char)(48 + num%7) + str;
            num/=7;
        }
        if(neg){
            str = '-' + str;
        }
        return str;
    }
};