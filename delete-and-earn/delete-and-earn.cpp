class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        
        int size = nums.size();
        int maxi[size];
        
        for(auto it : nums){
            mp[it]++;
        }
        
        int avoid = 0;
        int use = 0;
        int prev = -1;
        
        for(auto it : mp){
            int m = max(avoid,use);
            
            use = it.first * it.second;
            if(it.first - 1 != prev){
                use += m;
            }else{
                use += avoid;
            }
            avoid = m;
            prev = it.first;
        }
        
        return max(avoid,use);
    }
};