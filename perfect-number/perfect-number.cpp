class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                
                if(num %(num/i) == 0 && i!=num/i){
                    sum += (num/i);
                }
            }
        }
        return 2*num == sum;
    }
};