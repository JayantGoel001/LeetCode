class Solution {
public:
    vector<vector<int>> v;
    void generateSubSet(vector<int>& nums,int x,int n,vector<int> &sub){
        if(x == n){
            v.push_back(sub);
        }else{
            for(int i=x;i<n;i++){
                sub.push_back(nums[i]);
                generateSubSet(nums,i + 1,n,sub);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        
        for(int i=0;i<=size;i++){
            vector<int> sub;
            generateSubSet(nums,0,i,sub);
        }
        return v;
    }
};