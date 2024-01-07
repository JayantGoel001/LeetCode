#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        ll ans = 0;
        vector<unordered_map<ll,int>> count(size);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                ll delta = (ll)nums[i] - (ll)nums[j];
                int sum = 0;
                if(count[j].find(delta) != count[j].end()){
                    sum = count[j][delta];
                }
                count[i][delta] += sum + 1;
                ans += sum;
            }
        }
        return (int)ans;
    }
};