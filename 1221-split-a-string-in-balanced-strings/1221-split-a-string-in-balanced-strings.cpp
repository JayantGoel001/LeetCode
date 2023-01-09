class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int sum = 0;
        for(auto it : s){
            sum += (it == 'R' ? 1 : -1);
            count += (sum == 0);
        }
        return count;
    }
};