class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y;
        
        int count = 0;
        while(r!=0){
            if(r%2 == 1){
                count++;
            }
            r /=2;
        }
        return count;
    }
};