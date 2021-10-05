class Solution {
public:
    string toHex(long long int num) {
        if(num == 0){
            return "0";
        }
        if(num < 0){
            long long int n = 32;
            num = pow(2,n) + num;
        }
        
        string str = "";
        
        while(num){
            int x = num%16;
            
            if(x <= 9){
                str = (char)(x + 48) + str;
            }else{
                str = (char)(x + 87) + str;
            }
            num/=16;
        }
        return str;
    }
};