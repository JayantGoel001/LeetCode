class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq(k);
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(i >= k){
                v.push_back(nums[dq.front()]);
                while(!dq.empty() && i - dq.front() >= k){
                    dq.pop_front();
                }
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        v.push_back(nums[dq.front()]);
        return v;
    }
};