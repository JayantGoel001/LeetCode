#define ll long long 
class Solution {
public:
    ll power(ll x,int y){
        if(y == 0){
            return (ll)1;
        }else{
            if(y%2==0){
                return power(x * x, y/2);
            }else{
                return x * power(x * x, y/2);
            }
        }
    }
    ll findTheArrayConcVal(vector<int>& nums) {
        ll sum = 0;
        
        int i = 0;
        while(i < nums.size()/2){
            sum += (ll)nums[i] * power((ll)10, floor(log10(nums[nums.size() - i - 1])) + 1) + (ll)nums[nums.size() - i - 1];
            i++;
        }
        
        if(nums.size()%2){
            sum += nums[nums.size()/2];
        }
        return sum;
    }
};