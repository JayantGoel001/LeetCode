class Solution {
public:
    set<vector<int>> v;
    int n;

    void permutation(vector<int>& nums,int x){
        if(x == n){
            v.insert(nums);

        }else{
            for(int i = x;i<n;i++){
                swap(nums[i],nums[x]);

                permutation(nums,x+1);

                swap(nums[i],nums[x]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        permutation(nums,0);
        
        return vector<vector<int>>(v.begin(),v.end());
    }
};