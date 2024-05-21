class Solution {
public:
    vector<vector<int>> v;
    void generateSubSet(vector<int> &nums,vector<int> &temp,int n,int x=0){
        if(temp.size() == n){
            v.push_back(temp);
        }else{
            for(int i=x;i<nums.size();i++){
                temp.push_back(nums[i]);
                generateSubSet(nums,temp,n,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++){
            vector<int> temp;
            generateSubSet(nums,temp,i);        
        }
        return v;
    }
};