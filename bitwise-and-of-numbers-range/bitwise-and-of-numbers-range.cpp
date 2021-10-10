class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            c++;
        }
        return left<<=c;
    }
};