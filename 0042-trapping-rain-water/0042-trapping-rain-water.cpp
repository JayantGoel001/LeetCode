class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rightMax(height.size(), 0);

        rightMax[height.size() - 1] = height[height.size() - 1];
        
        for(int i=height.size()-2;i>=0;i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        int trapped = 0;
        int leftMax = height[0];
        for(int i=1;i < height.size() - 1;i++) {
            trapped += max(0, (min(leftMax, rightMax[i + 1]) - height[i]));
            leftMax = max(leftMax, height[i]);
        }
        
        return trapped;
    }
};