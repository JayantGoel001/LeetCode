class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        vector<int> ans;
        int l1 = l - 1;
        int r1 = l;
        while (k) {
            int lVal = l1 < 0 ? INT_MIN + 10000 : arr[l1]; 
            int rVal = r1 >= arr.size() ? INT_MAX - 10000 : arr[r1];
            if (abs(lVal - x) <= abs(rVal - x)) {
                ans.push_back(lVal);
                l1--;
            } else {
                ans.push_back(rVal);
                r1++;
            }
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};