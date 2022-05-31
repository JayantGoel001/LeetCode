class Solution {
public:
    int minOperations(int n) {
        if(n%2){
            int x = n/2 + 1;
            return x * (x - 1);
        }else{
            int x = n/2;
            return x * x;
        }
    }
};