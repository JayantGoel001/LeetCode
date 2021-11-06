class Solution {
public:
    int findMedian(int *v,int  n){
        sort(v,v + n);
        
        return v[n/2];
    }
    int partition(int *v,int l,int r,int mid){
        int i;
        for(i=l;i<r;i++){
            if(v[i] == mid){
                break;
            }
        }
        swap(v[i],v[r]);
        
        i = l;
        for(int j = l;j<r;j++){
            if(v[j] >= mid){
                swap(v[i],v[j]);
                i++;
            }
        }
        swap(v[i],v[r]);
        return i;
    }
    int kthLargest(int *nums,int l,int r,int k){
        
        int n = r - l + 1;
        if(k > 0 && k<=n){
            int median[(n+4)/5];
            int i;
            for(i=0;i<n/5;i++){
                median[i] = findMedian((nums + l + i * 5), 5);
            }
            if(i * 5 < n){
                median[i] = findMedian((nums + l + i * 5), n%5);
                i++;
            }

            int mid = (i == 1) ? median[0] : kthLargest(median,0,i - 1,i/2);

            int pos = partition(nums,l,r,mid);

            if(pos - l == k - 1){
                return nums[pos];
            }else if(pos - l > k - 1){
                return kthLargest(nums,l,pos - 1,k);
            }else{
                return kthLargest(nums,pos + 1,r,k - pos + l - 1);
            }
        }
        return INT_MAX;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int ar[nums.size()];
        for(int i = 0;i<nums.size();i++){
            ar[i] = nums[i];
        }
        return kthLargest(ar,0,nums.size()-1,k);
    }
};