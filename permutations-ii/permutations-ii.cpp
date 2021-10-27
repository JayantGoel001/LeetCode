class Solution {
public:
    set<vector<int>> v;
    void generatePermutations(vector<int>& nums,int x,int n){
        if(x == n){
            v.insert(nums);
        }else{
            for(int i=x;i<n;i++){
                swap(nums[x],nums[i]);
                generatePermutations(nums,x+1,n);
                swap(nums[x],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> per;
        generatePermutations(nums,0,n);
        return vector<vector<int>>(v.begin(),v.end());
    }
};