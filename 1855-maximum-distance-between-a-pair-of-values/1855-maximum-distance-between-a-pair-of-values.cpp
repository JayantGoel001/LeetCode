class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j;

        for (i = 0, j = 0; i < A.size() && j < B.size(); j++)
            i += A[i] > B[j];

        return max(0, j - i - 1);
    }
};