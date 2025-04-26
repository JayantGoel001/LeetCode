#define ll long long 
class Solution {
public:
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll answer = 0;
        int left = -1;
        int minP = -1;
        int maxP = -1;
        
        for(int i=0;i<nums.size();i++){
            if(minK > nums[i] || maxK < nums[i]){
                left = i;
            }
            if(minK == nums[i]){
                minP = i;
            }
            if(maxK == nums[i]){
                maxP = i;
            }
            
            answer += max(min(maxP, minP) - left, 0);
        }
        return answer;
    }
};