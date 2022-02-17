class Solution {
public:
    vector<int> temp;
    int merge(vector<int> &nums,int low,int mid,int high){
        int count = 0;
        int j = mid;
        for(int i=low;i<mid;i++){
            while(j <= high && (long long)nums[i] > 2 * (long long)nums[j]){
                j++;
            }
            count += (j - mid);
        }
        
        int i = low;
        j = mid;
        int k = low;
        
        while(i < mid && j <= high){
            if(nums[i] < nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        
        while(i < mid){
            temp[k++] = nums[i++];
        }
        while(j <= high){
            temp[k++] = nums[j++];
        }
        
        for(i = low;i<=high;i++){
            nums[i] = temp[i];
        }
        return count;
    }
    int mergeSort(vector<int> &nums,int i,int j){
        int count = 0;
        if(i < j){
            int mid = (i + j)/2;
            
            count += mergeSort(nums,i,mid);
            count += mergeSort(nums,mid+1,j);
            
            count += merge(nums,i,mid+1,j);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(0);
        }
        return mergeSort(nums,0,n-1);
    }
};