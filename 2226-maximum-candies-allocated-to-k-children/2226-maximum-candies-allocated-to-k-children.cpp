#define ll long long int
class Solution {
public:
    long long checkCan(vector<int>& candies,int mid){
        long long count = 0;
        for(auto it : candies){
            count += (ll)it/mid;
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = INT_MIN;
        for(auto it : candies){
            maxi = max(maxi,it);
        }
        int low = 1;
        int high = maxi;
        int out = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            long long res = checkCan(candies,mid);
            if(res >= k){
                out = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return out;
    }
};