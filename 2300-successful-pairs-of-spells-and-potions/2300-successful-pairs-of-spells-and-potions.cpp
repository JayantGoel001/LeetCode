class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> res;
        for(int spell : spells) {
            double successThreshold = (double)success/spell;

            res.push_back(potions.end() - lower_bound(potions.begin(), potions.end(), successThreshold));
        }

        return res;
    }
};