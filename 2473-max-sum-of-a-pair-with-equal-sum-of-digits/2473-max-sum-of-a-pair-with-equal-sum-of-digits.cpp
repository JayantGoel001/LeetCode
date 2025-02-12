class Solution {
public:
    int sumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int, vector<int>, greater<int>>> mp;
        
        for(auto num : nums){
            mp[sumOfDigits(num)].push(num);
            if(mp[sumOfDigits(num)].size() > 2){
                mp[sumOfDigits(num)].pop();
            }
        }
        int maxi = -1;
        for(auto it : mp){
            int sum = 0;
            if(it.second.size() == 2){
                while(!it.second.empty()){
                    sum += it.second.top();
                    it.second.pop();
                }
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};