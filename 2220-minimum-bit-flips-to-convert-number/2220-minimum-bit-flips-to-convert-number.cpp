class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int x = start ^ goal;
        while(x){
            count += x%2;
            x/=2;
        }
        return count;
    }
};