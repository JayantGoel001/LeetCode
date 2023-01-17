class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int ones = 0;
        
        for(auto it : s){
            if(it == '0'){
                ans = min(ones, ans + 1);
            }else{
                ones++;
            }
        }
        return ans;
    }
};