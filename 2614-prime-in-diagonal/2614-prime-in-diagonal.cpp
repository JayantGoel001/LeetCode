class Solution {
public:
    bool isPrime(int x){
        for(int i=2;i*i<=x;i++){
            if(x%i == 0){
                return false;
            }
        }
        return x!=1;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i][i] > res && isPrime(nums[i][i])){
                res = nums[i][i];
            }
            if(nums[i][nums.size() - i - 1] > res && isPrime(nums[i][nums.size() - i - 1])){
                res = nums[i][nums.size() - i - 1];
            }
        }
        return res;
    }
};