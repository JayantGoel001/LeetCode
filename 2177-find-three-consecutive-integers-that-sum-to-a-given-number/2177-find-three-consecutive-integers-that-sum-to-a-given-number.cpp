class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> v;
        if(num%3==0){
            long long x = num/3 - 1;
            v.push_back(x);
            v.push_back(x+1);
            v.push_back(x+2);
        }
        return v;
    }
};