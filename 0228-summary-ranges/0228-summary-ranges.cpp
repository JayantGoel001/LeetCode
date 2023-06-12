class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int prev = INT_MIN;
        vector<string> v;
        string str = "";
        int n = nums.size();
        
        int i = 0;
        while(i < n){
            str = to_string(nums[i]);
            int x = i;
            while(i + 1 < n && nums[i] + 1 == nums[i + 1]){
                i++;
            }
            if(x != i){
                str.append("->");
                str.append(to_string(nums[i]));   
            }
            
            v.push_back(str);

            str = "";
            i++;
        }
        return v;
    }
};