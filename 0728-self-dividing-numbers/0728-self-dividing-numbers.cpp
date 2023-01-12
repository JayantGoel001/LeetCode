class Solution {
public:
    bool check(int num){
        int temp = num;
        while(temp){
            int x = temp%10;
            if(x == 0 || num % x != 0){
                return false;
            }
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        while(left <= right){
            if(check(left)){
                v.push_back(left);
            }
            left++;
        }
        return v;
    }
};