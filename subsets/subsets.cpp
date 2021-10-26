class Solution {
public:
    vector<vector<int>> v;
    void generateSubSet(vector<int>& nums,int x,int n,vector<int> &sub){
        v.push_back(sub);
        for(int i=x;i<n;i++){
            sub.push_back(nums[i]);
            generateSubSet(nums,i + 1,n,sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<int> sub;
        generateSubSet(nums,0,size,sub);
        return v;
    }
};