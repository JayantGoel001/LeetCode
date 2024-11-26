class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        // Store the indegree of each team.
        for (auto edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1, champCount = 0;
        for (int i = 0; i < n; i++) {
            // If the team can be chamption, store the number and count of such
            // teams.
            if (indegree[i] == 0) {
                champCount++;
                champ = i;
            }
        }

        // If more than one champion, return -1 else return the team number.
        return champCount > 1 ? -1 : champ;
    }
};