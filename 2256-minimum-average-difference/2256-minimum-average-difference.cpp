#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll sum = 0;
        for(auto it : nums){
            sum += it;
        }
        int mini = INT_MAX;
        ll s = 0;
        int index = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            int x = s/(i + 1) - (nums.size() == i + 1 ? 0 : (sum - s)/(nums.size() - i - 1));
            if(abs(x) < mini){
                index = i;
                mini = abs(x);
            }
        }
        return index;
    }
};