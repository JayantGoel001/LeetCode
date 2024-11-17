class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int n=nums.size();
        long long sum[n];// prefix sum 0-index
        sum[0]=nums[0];

        int dp[n], front=0, back=-1, len=1e9;// deque dp
        for(int r=0; r<n; r++){
            if (r>0) sum[r]=sum[r-1]+nums[r];
            if (sum[r]>=k) len=min(len, r+1);
            while(front<=back && sum[r]-sum[dp[front]]>=k){
                len=min(len, r-dp[front]);
                front++;
            }
            while(front<=back && sum[r]<=sum[dp[back]]) back--;
            dp[++back]=r;
        }
        return len==1e9?-1:len;
    }
};