class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while(n!=1){
            count += n/2;
            n = ceil(n/2.0);
        }
        return count;
    }
};