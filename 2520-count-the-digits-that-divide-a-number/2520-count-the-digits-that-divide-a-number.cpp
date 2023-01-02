class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        
        int x = num;
        while(x){
            int y = x % 10;
            
            count += (num%y == 0);
            
            x/=10;
        }
        
        return count;
    }
};