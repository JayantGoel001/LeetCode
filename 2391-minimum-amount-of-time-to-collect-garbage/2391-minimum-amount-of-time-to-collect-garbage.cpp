class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Store the prefix sum in travel itself.
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i - 1] + travel[i];
        }
        
        // Map to store garbage type to the last house index.
        unordered_map<char, int> garbageLastPos;
        int ans = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                garbageLastPos[c] = i;
            }
            ans +=  garbage[i].size();
        }
        
        string garbageTypes = "MPG";
        for (char c : garbageTypes) {
            // No travel time is required if the last house is at index 0.
            ans += (garbageLastPos[c] == 0 ? 0 : travel[garbageLastPos[c] - 1]);
        }
        
        return ans;
    }
};