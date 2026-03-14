class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto it : asteroids) {
            while(!res.empty() && res.back() > 0 && it < 0 && res.back() < -it) {
                res.pop_back();
            }

            if (res.empty() || res.back() < 0 || it > 0) {
                res.push_back(it);
                continue;
            }

            if (res.back() == -it) {
                res.pop_back();
                continue;
            }
            
            if (-it < res.back()) continue;
            
            res.push_back(it);
        }

        return res;
    }
};