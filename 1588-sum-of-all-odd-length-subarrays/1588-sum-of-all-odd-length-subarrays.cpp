class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int size = arr.size();
        for(int i=0;i<size;i++){
            sum += arr[i] * ceil(((size - i ) * (i + 1))/2.0);
        }
        return sum;
    }
};