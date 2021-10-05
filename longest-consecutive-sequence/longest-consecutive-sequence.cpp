class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto it : nums){
            s.insert(it);
        }
        int maxi = 0;
        for(auto it : nums){
            if(s.find(it-1) == s.end()){
                int num = it;
                int cur = 1;
                
                while(s.find(num+1)!=s.end()){
                    cur++;
                    num++;
                }
                
                maxi = max(maxi,cur);
            }
        }
        return maxi;
    }
};