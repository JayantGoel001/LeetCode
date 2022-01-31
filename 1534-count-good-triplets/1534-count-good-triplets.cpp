class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int size = arr.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(int k=j+1;k<size;k++){
                    count += (abs(arr[i] - arr[j])<=a && abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c);
                }
            }
        }
        return count;
    }
};