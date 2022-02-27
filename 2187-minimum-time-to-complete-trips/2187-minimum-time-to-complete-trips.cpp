class Solution {
public:
    bool isOK(vector<int>& time, long long x ,int k){
        long long count = 0;
        for(auto it : time){
            count += (long long)x/it;
        }
        return count >= k;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it : time){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }
        long long i = mini;
        long long j = (long long)maxi * totalTrips;
        
        while(i <= j){
            long long mid = i + (j - i)/2;
            if(isOK(time,mid,totalTrips)){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        return i;
    }
};