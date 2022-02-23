class Solution {
public:
     vector<long long> maximumEvenSplit(long long x) {
        vector<long long> v;
        if(x%2 == 0){
            long long num = 2L;
            while(x){
                if(x >= num){
                    x -= num;
                    v.push_back(num);
                }else{
                    int prev = v.back();
                    v.pop_back();
                    v.push_back(x + prev);
                    x = 0;
                }
                num += 2;
            }
        }
        return v;
     }
};