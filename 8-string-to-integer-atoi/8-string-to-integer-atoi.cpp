class Solution {
public:
    int myAtoi(string s) {
        int i =0;
        long long int num = 0;
        while(i<s.size() && s[i]==' '){ i++; }
        if(i == s.size()){
            return num;
        }
        
        bool minus = false;
        if(s[i]=='-' || s[i]=='+'){
            minus = (s[i++]=='-');
        }
        
        while(i<s.size()){
            if(s[i] >= '0' && s[i]<='9'){
                num = num*10 + (s[i] - 48); 
                if(num >INT_MAX){
                    if(minus){
                        return -2147483648;
                    }else{
                        return 2147483647;
                    }
                }
            }else{
                break;
            }
            i++;
        }
        if(minus){
            num = -1 * num;
        }
        return num;
    }
};