class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right, vector<int> &temp){
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right- mid;
        
        for(int i=0;i<n1;i++){
            temp[start1 + i] = nums[start1 + i];
        }
        for(int i=0;i<n2;i++){
            temp[start2 + i] = nums[start2 + i];
        }
        
        int i = 0;
        int j = 0;
        int k = left;
        
        while(i < n1 && j < n2){
            if(temp[start1 + i] <= temp[start2 + j]){
                nums[k] = temp[start1 + i];
                i++;
            }else{
                nums[k] = temp[start2 + j];
                j++;
            }
            k++;
        }
        while(i < n1){
            nums[k++] = temp[start1 + i];
            i++;
        }
        while(j < n2){
            nums[k++] = temp[start2 + j];
            j++;
        }
    }
    void mergeSort(vector<int> &nums, int left, int right, vector<int> &temp){
        if(left >= right){
            return;
        }
        int mid = (left + right)/2;
        
        mergeSort(nums,left,mid,temp);
        mergeSort(nums,mid + 1,right,temp);
        
        merge(nums,left,mid,right,temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        
        return nums;
    }
};