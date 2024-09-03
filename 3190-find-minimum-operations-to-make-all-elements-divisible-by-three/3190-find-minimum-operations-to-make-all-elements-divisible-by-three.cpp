class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int mini = 0;
        for(auto it : nums) {
            
            mini += min(abs(3 - it % 3), it % 3);
        }
        
        return mini;
    }
};