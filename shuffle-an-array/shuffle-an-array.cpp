class Solution {
public:
    vector<int> nums;
    vector<int> org;
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->org = nums;
    }
    
    vector<int> reset() {
        this->nums = this->org;
        return this->nums;
    }
    
    vector<int> shuffle() {
        int size = this->nums.size();
        for(int i=0;i<size;i++){
            int pos = rand() % (size - i);
            swap(this->nums[i + pos],this->nums[i]);
        }
        return nums;
    }
};