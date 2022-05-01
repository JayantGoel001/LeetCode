class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int count = 0;
        unordered_map<string,int> mp;
        for(int i=0;i<nums.size();i++){
            int countK = 0;
            int j;
            string str = "";
            
            for(j=i;j<nums.size();j++){
                countK += (nums[j]%p == 0 ? 1 : 0);
                if(countK > k){
                    break;
                }
                
                str += (nums[j] + '0');
                mp[str]++;
            }
            count += (j - i);
        }
        for(auto it : mp){
            count -= (it.second - 1);
        }
        return count;
    }
};