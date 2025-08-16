class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num){
            rev = rev * 10 + num%10;
            num/=10;
        }
        return rev;
    }
    int maximum69Number (int num) {
        int res = 0;
        bool found = false;
        num = reverse(num);
        while(num){
            int x = num%10;
            if(x == 6 && !found){
                res = res * 10 + 9;
                found = true;
            }else{
                res = res * 10 + x;
            }
            num/=10;
        }
        return res;
    }
};