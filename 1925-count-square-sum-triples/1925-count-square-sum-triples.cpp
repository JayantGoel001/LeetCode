class Solution {
public:
    bool checkSqrt(int c, int low, int high){
        long long mid = 0;
        while(low <= high){
            mid = (long long)low + (high - low)/2;
            
            if(mid * mid == c){
                return true;
            }else if(mid * mid < c){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return mid * mid == c;
    }
    int countTriples(int n) {
        int count = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                count += checkSqrt(i * i + j * j, max(i, j), n);
            }
        }
        return count;
    }
};