class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i] * ceil((i + 1) * (arr.size() - i)/2.0);
        }
        return sum;
    }
};