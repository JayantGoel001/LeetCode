class Solution {
public:
    vector<vector<int>> v;
    
    void generateSubset(vector<int> &nums,int x,int n,vector<int> &sub){
        v.push_back(sub);
        for(int i=x;i<n;i++){
            if(i == x || nums[i] != nums[i-1]){
                sub.push_back(nums[i]);
                generateSubset(nums,i+1,n,sub);
                sub.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        vector<int> sub;
        generateSubset(nums,0,n,sub);
        return v;
    }
};