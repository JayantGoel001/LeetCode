class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        
        int prev = -1;
        int avoid = 0;
        int use = 0;
        
        for(auto it : mp){
            int temp = max(use,avoid);
            use = it.first * it.second;
            
            if(it.first != prev + 1){
                use += temp;
            }else{
                use += avoid;
            }
            avoid = temp;
            prev = it.first;
        }
        
        return max(use, avoid);
    }
};