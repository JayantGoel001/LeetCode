class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int n1 = num1.size();
        int n2 = num2.size();
        int N = n1 + n2;
        
        string str(N,'0');
        
        for(int i=n2-1;i>=0;i--){
            int d2 = num2[i] - '0';
            
            for(int j=n1-1;j>=0;j--){
                int d1 = num1[j] - '0';
                int zeroes = n1 + n2 - i - j - 2;
                int carry = str[zeroes] - '0';
                
                int x = d1 * d2 + carry;
                str[zeroes] = (x%10) + '0';
                
                str[zeroes + 1] += (x/10);
            }
        }
        if(str.back() == '0'){
            str.pop_back();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};