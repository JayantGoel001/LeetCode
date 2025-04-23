class Solution {
public:
    int sum(int x){
        int s = 0;
        while(x){
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[sum(i)]++;
        }
        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        int count = 0;
        for(auto it : mp){
            count += maxi == it.second;
        }
        return count;
    }
};