#define ll long long
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll sum = 0;
        int i = 1;
        int prev = 0;
        
        for(auto it : nums){
            int x = it - prev - 1;
            if(x <= 0){
                prev = it;
            }else{
                if(k >= x){
                    k -= x;
                    sum += ((ll)(prev + it) * x)/2;
                    prev = it;
                    
                    if(k == 0){
                        break;
                    }
                }else{
                    sum += (((ll)prev + 1 + prev + k) * k)/2;
                    k = 0;
                    break;
                }
            }
        }
        if(k == 0){
            return sum;
        }
        sum += ((2 * (ll)nums.back() + 1 + k) * k)/2;
        return sum;
    }
};