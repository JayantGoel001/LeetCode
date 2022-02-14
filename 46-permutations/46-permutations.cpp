class Solution {
public:
    vector<vector<int>> v;
    
    void generatePerm(vector<int> &nums,int size,int x=0){
        if(x == size){
            v.push_back(nums);
        }else{
            for(int i=x;i<size;i++){
                swap(nums[i],nums[x]);
                generatePerm(nums,size,x+1);
                swap(nums[i],nums[x]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        generatePerm(nums,nums.size());
        return v;
    }
};