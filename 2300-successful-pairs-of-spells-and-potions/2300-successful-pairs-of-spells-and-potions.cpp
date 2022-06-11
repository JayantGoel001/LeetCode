class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        
        sort(potions.begin(),potions.end());
        
        for(auto spell : spells){
            double s = (double)success/spell;
            int pos = lower_bound(potions.begin(),potions.end(),s) - potions.begin();
            res.push_back(potions.size() - pos);
        }
        return res;
    }
};