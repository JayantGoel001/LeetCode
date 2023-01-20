class Solution {
public:
    set<vector<int>> v;
    
    void backtrack(vector<int>& nums, int pos, vector<int> &seq){
        if(pos == nums.size()){
            if(seq.size() >= 2){
                v.insert(seq);
            }
            return;
        }
        if(seq.empty() || seq.back() <= nums[pos]){
            seq.push_back(nums[pos]);
            backtrack(nums, pos + 1, seq);
            seq.pop_back();
        }
        backtrack(nums, pos + 1, seq);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        backtrack(nums, 0, seq);
        
        return vector<vector<int>>(v.begin(), v.end());
    }
};