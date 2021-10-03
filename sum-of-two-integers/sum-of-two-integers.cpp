class Solution {
public:
    int getSum(int a, int b) {
        return round(log(pow(1.1,a) * pow(1.1,b))/log(1.1));
    }
};