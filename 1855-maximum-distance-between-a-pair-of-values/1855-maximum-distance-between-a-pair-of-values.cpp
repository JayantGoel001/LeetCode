class Solution {
public:
    int maxDistance(vector<int>& n1, vector<int>& n2) {
        int i = 0, j = 0, res = 0;
        while (i < n1.size() && j < n2.size())
            if (n1[i] > n2[j])
                ++i;
            else
                res = max(res, j++ - i);
        return res;
    }
};