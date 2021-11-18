class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int can1 = INT_MIN;
        int can2 = INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==can1){
                count1++;
            }else if(nums[i]==can2){
                count2++;
            }else if(count1==0){
                can1 = nums[i];
                count1++;
            }else if(count2==0){
                can2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==can1){
                count1++;
            }
            if(nums[i]==can2){
                count2++;
            }
        }
        vector<int> v;
        if(count1>nums.size()/3){
            v.push_back(can1);
        }
        if(can1!=can2 && count2>nums.size()/3){
            v.push_back(can2);
        }
        return v;
    }
};