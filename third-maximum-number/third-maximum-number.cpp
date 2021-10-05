class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        
        unordered_set<int> s(nums.begin(),nums.end());
        
        
        for(auto it : s){
            if(first <= it){
                third = second;
                second = first;
                first = it;
            }else if(second <= it){
                third = second;
                second = it;
            }else if(third <= it){
                third = it;
            }
        }
        
        return s.size()>=3 ? third : first;
    }
};