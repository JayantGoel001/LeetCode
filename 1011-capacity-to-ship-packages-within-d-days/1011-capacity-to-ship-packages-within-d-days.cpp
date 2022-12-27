class Solution {
public:
    bool check(vector<int>& weights, int mid, int days){
        int x = 1;
        int sum = 0;
        for(auto it : weights){
            if(it > mid){
                return true;
            }
            sum += it;
            if(sum > mid){
                x++;
                sum = it;
                if(x > days){
                    return true;
                }
            }
        }
        
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        for(auto it : weights){
            high += it;
        }
        int mid = 0;
        int ans = INT_MAX;
        while(low <= high){
            mid = (low + high)/2;
    
            if(check(weights, mid, days)){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};