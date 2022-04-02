class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        
        v.push_back({1});
        for(int i = 1;i<=rowIndex;i++){
            vector<int> v2;
            v2.push_back(1);
            
            for(int j = 1;j<i;j++){
                v2.push_back((v[j-1] + v[j])%10);
            }
            
            v2.push_back(1);
            
            v = v2;
        }
        return v;
    }
    int triangularSum(vector<int>& nums) {
       vector<int> v = getRow(nums.size() - 1) ;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res = (res + ((nums[i]%10) * (v[i]%10))%10)%10;
        }
        return res;
    }
};