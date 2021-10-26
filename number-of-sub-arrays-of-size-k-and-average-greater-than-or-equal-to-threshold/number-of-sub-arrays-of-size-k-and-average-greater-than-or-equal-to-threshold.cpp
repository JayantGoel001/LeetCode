class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int n = arr.size();
        
        int count = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(i >= k){
                sum -= arr[i - k];
            }
            if(i >= (k - 1) && sum >= threshold * k){
                count++;
            }
        }
        return count;
    }
};