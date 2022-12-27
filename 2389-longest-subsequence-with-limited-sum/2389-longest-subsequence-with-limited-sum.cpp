class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());

        vector<int> ans;
        for(int q : queries){
            int len = 0;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                sum += nums[i];
                len = i;

                if(sum > q){
                    break;
                }
            }
            if(sum <= q){
                len++;
            }
            ans.push_back(len);
        }
        return ans;
    }
};