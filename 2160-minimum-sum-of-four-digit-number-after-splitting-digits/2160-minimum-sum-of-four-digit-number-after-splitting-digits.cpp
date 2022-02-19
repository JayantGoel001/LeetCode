class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(),v.end());
        return 10 * (v[0] + v[1]) + (v[2] + v[3]);
    }
};