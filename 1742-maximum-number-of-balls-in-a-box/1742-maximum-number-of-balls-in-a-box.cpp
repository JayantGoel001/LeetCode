class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;
        for(int i=lowLimit;i<=highLimit;i++){
            int num = i;
            int sum = 0;
            while(num){
                sum += num%10;
                num/=10;
            }
            mp[sum]++;
        }
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};