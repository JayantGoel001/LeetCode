class Solution {
public:
    vector<vector<int>> v;
    
    void generateSubset(vector<int> &nums,int n,int size,vector<int> &temp,int x=0){
        if(size == temp.size()){
            v.push_back(temp);
        }else{
            for(int i=x;i<n;i++){
                if(i == x || nums[i-1] != nums[i]){
                    temp.push_back(nums[i]);
                    generateSubset(nums,n,size,temp,i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        
        for(int i=0;i<=nums.size();i++){
            generateSubset(nums,nums.size(),i,temp);
        }
        return v;
    }
};