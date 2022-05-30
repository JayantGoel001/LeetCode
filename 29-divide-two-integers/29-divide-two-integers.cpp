class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) 
           return INT_MAX;

        long long count = 0; 
        long long int div  = abs(dividend);
        long long int dis  = abs(divisor);
        long long int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

        while(div>=dis){
            long long int temp = dis, m=1;
            while((temp<<1) <= div){
                temp<<=1;
                m<<=1;
            }
            div -= temp;
            count += m;
        }
        return sign * count;
    }
};