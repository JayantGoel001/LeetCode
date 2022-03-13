class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k == 0){
            return nums[0];
        }
        if(k > nums.size()){
            int maxi = 0;
            for(auto it : nums){
                maxi = max(maxi,it);
            }
            if(k%2 && nums.size() == 1){
                return -1;
            }
            return maxi;
        }
        priority_queue<int> pq;
        int i = 0;
        while(k > 1){
            pq.push(nums[i++]);
            k--;
        }
        if(i + 1 >= nums.size() && pq.empty()){
            return -1;
        }else if(i + 1 < nums.size() && !pq.empty()){
            return max(nums[i + 1],pq.top());
        }else if(i + 1< nums.size()){
            return nums[i + 1];
        }else{
            return pq.top();
        }
    }
};