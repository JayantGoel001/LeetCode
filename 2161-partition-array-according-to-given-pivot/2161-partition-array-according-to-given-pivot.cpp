class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for(auto it : nums){
            if(it < pivot){
                v.push_back(it);
            }
        }
        for(auto it : nums){
            if(it == pivot){
                v.push_back(it);
            }
        }
        for(auto it : nums){
            if(it > pivot){
                v.push_back(it);
            }
        }
        return v;
    }
};