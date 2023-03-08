class Solution {
public:
    bool isMinimum(vector<int> &piles, int k, int h){
        int count = 0;
        for(auto it : piles){
            count += ceil(it/(double)k);
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        
        for(auto it : piles){
            high = max(high, it);
        }
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            if(isMinimum(piles,mid,h)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};