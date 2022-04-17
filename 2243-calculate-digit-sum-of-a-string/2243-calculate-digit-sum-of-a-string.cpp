class Solution {
public:
    string getSum(string &s,int x,int k){
        int sum = 0;
        for(int i = x;i < s.size() && i < x + k;i++){
            sum = sum + (s[i] - '0');
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
    
        while(s.size() > k){
            string str = "";
            for(int i=0;i<s.size();i+=k){
                str.append(getSum(s,i,k));
            }
            s = str;
        }
        return s;
    }
};