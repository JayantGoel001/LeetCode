class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
};