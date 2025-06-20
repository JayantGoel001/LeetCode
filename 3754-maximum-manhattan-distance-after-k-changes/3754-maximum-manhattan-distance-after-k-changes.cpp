class Solution {
public:
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};