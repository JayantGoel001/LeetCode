class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int _5 = ceil(n * 0.05);
        
        double sum = 0.0;
        int count = 0;
        for(int i = _5;i < n - _5;i++){
            sum += arr[i];
            count++;
        }
        return sum/count;
    }
};