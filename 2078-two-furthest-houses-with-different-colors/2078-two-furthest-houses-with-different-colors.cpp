class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int j = colors.size() - 1;
        while(j >= 0 && colors[0] == colors[j]){
            j--;
        }
        
        int i = 0;
        while(i < colors.size() && colors[i] == colors[colors.size() - 1]){
            i++;
        }
        return max((int)colors.size() - i - 1, j);
    }
};