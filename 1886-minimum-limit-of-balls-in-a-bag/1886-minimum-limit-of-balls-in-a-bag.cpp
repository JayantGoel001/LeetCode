class Solution {
public:
     bool ispossible(int mid , vector<int> &nums , int ops){
        int count=0;
        
        for(int i=0;i<nums.size();i++){
           if(nums[i]%mid==0){
               count+=(nums[i]/mid  - 1);
           }else{
               count+=(nums[i]/mid);
            }
        }
        
        return count<=ops;
    }
    int minimumSize(vector<int>& nums, int ops) {
        int n=nums.size();
        
        int l=1 , r=*max_element(nums.begin(),nums.end());
              
        int ans;
        
        while(l<=r){
            int mid=(l+(r-l)/2);
            
            if(ispossible(mid , nums , ops)==true){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return l;
    }
};