class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),
             asteroids.end());  // Sort by mass in ascending order
        long long mass1 = mass;
        for (const int asteroid : asteroids) {
            // Traverse the asteroids in order, attempt to destroy and update
            // mass or return the result
            if (mass1 < asteroid) {
                return false;
            }
            mass1 += asteroid;
        }
        return true;  // Successfully destroy all asteroids
    }
};