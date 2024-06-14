class Solution {
public:
     unordered_map<int, int> root;
    int minIncrementForUnique(vector<int>& A) {
        int res = 0;
        for (int a : A)
            res += find(a) - a;
        return res;
    }
    int find(int x) {
        return root[x] = root.count(x) ? find(root[x] + 1) : x;
    }
};