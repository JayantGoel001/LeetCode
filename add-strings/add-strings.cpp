class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string str = "";
        int carry = 0;
        while(i>=0 && j>=0){
            int x = (num1[i] - '0') + (num2[j] - '0') + carry;
            int rem = x%10;
            carry = x/10;
            
            str = (char)(rem + '0') + str;
            i--;
            j--;
        }
        while(i >= 0){
            int x = (num1[i] - '0') + carry;
            int rem = x%10;
            carry = x/10;
            
            str = (char)(rem + '0') + str;
            i--;
        }
        while(j >= 0){
            int x = (num2[j] - '0') + carry;
            int rem = x%10;
            carry = x/10;
            
            str = (char)(rem + '0') + str;
            j--;
        }
        if(carry){
            str = (char)(carry + '0') + str;
        }
        return str;
    }
};