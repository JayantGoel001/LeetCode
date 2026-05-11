class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        
        for(auto it : nums){
            string str = to_string(it);
            for(auto s : str){
                v.push_back(s - '0');
            }
        }
        return v;
    }
};