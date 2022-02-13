class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        
        int res = 0;
        int leftMax = 0;
        int rightMax = 0;
        
        while(i<=j){
            if(height[i] < height[j]){
                if(height[i] > leftMax){
                    leftMax = height[i];
                }else{
                    res += (leftMax - height[i]);
                }
                i++;
            }else{
                if(height[j] > rightMax){
                    rightMax = height[j];
                }else{
                    res += (rightMax - height[j]);
                }
                j--;
            }
        }
        return res;
    }
};