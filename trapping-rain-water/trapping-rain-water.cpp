class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0;
        int right = h.size()-1;
        
        int leftMax = 0;
        int rightMax = 0;
        
        int output = 0;
        
        while(left <= right){
            if(h[left] < h[right]){
                if(leftMax < h[left]){
                    leftMax = h[left];
                }else{
                    output += (leftMax - h[left]);
                }
                left++;
            }else{
                if(rightMax < h[right]){
                    rightMax = h[right];
                }else{
                    output += (rightMax - h[right]);
                }
                right--;
            }
        }
        return output;
    }
};