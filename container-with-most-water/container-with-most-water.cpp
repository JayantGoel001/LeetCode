class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        
        int maxi = 0;
        while(low <= high){
            maxi = max(maxi,min(height[low],height[high]) * (high - low));
            
            if(height[low] < height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxi;
    }
};