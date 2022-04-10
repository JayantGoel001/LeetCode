#define ll long long int
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums[0] + k;
        }
        ll MOD = 1e9 + 7;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(auto it : nums){
            pq.push((ll)it);
        }
        while(k > 0){
            ll top = pq.top();
            pq.pop();
            
            ll diff = pq.top() - top;
            if(diff + 1 <= k){
                k -= (diff + 1);
                pq.push(pq.top() + 1);
            }else{
                pq.push(top + k);
                k = 0;
            }
        }
        ll res = 1;
        while(!pq.empty()){
            res = ((res%MOD) * (pq.top()%MOD))%MOD;
            pq.pop();
        }
        return res;
    }
};