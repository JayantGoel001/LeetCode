class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> a(size,0),b(size,1);
        
        a[0] = nums[0];
        b[size-1] = nums[size-1];
        
        for(int i=1;i<size;i++){
            a[i] = nums[i] * a[i-1];
        }
        
        for(int i=size-2;i>=0;i--){
            b[i] = nums[i] * b[i + 1];
        }
        
        for(int i=0;i<size;i++){
            nums[i] = 1;
            
            if(i>0){
                nums[i] *= a[i - 1];
            }
            if(i + 1<size){
                nums[i] *= b[i + 1];
            }
        }
        return nums;
    }
};