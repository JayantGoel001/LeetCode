class Solution {
public:
    int getK(vector<int> nums1, vector<int> nums2,int n,int m,int k){
        if(n == 0){
            return nums2[k-1];
        }
        if(m == 0){
            return nums1[k-1];
        }
        if(k == 1){
            return min(nums1[0],nums2[0]);
        }
        int i =  min(n,k/2);
        int j = min(m,k/2);
        
        if(nums1[i-1] < nums2[j-1]){
            return getK(vector<int> (nums1.begin()+i,nums1.end()),nums2,n-i,m,k-i);
        }else{
            return getK(nums1,vector<int> (nums2.begin()+j,nums2.end()),n,m-j,k-j);
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int k = (n + m)/2;
        int m1 = getK(nums1,nums2,n,m,k + 1);
        int m2 = m1;
        if((n + m)%2 == 0){
            m2 = getK(nums1,nums2,n,m,k);
        }
        return (m1 + m2)/2.0;
    }
};