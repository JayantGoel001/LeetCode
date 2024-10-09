class Solution {
public:
    int longestMountain(vector<int>& v) {
        int maxi = 0;
        int last = 0;
        
        if (v.size() < 3) return maxi;
        
        int i=0;
        while(i < v.size()) {
            int x = i;
            while (x < v.size() - 1 && v[x] < v[x + 1]) {
                x++;
            }
            
            if (x != i) {
                
                int y = x;
                while (y < v.size() - 1 && v[y] > v[y + 1]) {
                    y++;
                }
            
                if (y != x) {
                    maxi = max(maxi, y - i + 1);
                    i = y;
                } else {
                    i = x;
                }
            } else {
                i++;
            } 
        }
        
        return maxi;
    }
};