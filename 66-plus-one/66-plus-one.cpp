class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        for(int i =0;i<digits.size();i++){
            int x = (digits[i] + carry);
            digits[i] = x%10;
            carry = x/10;
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};