class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiaSq = 0, maxArea = 0;
        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diaSq = l * l + w * w, area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};