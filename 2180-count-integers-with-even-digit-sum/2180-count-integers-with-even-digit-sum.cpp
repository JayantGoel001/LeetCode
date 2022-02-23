class Solution {
public:
    int checkSum(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x/=10;
        }
        return sum%2==0;
    }
    int countEven(int num) {
        int count = 0;
        int i = 1;
        while(i <= num){
            count += checkSum(i);
            i++;
        }
        return count;
    }
};