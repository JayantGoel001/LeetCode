class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int low = 0;
        int high = height.size()-1;
        
        while(low <= high){
            maxArea = max(maxArea,min(height[low],height[high]) * (high - low));
            if(height[low] < height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxArea;
    }
};