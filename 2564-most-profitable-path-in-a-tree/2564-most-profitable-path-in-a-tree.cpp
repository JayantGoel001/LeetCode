class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        n = amount.size();
        tree.resize(n, vector<int>());

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        distanceFromBob.resize(n);
        return findPaths(0, 0, 0, bob, amount);
    }

private:
    vector<vector<int>> tree;
    vector<int> distanceFromBob;
    int n;

    // Depth-first Search
    int findPaths(int sourceNode, int parentNode, int time, int bob,
                  vector<int>& amount) {
        int maxIncome = 0, maxChild = INT_MIN;

        // Find the node distances from Bob
        if (sourceNode == bob)
            distanceFromBob[sourceNode] = 0;
        else
            distanceFromBob[sourceNode] = n;
        for (int adjacentNode : tree[sourceNode]) {
            if (adjacentNode != parentNode) {
                maxChild = max(maxChild, findPaths(adjacentNode, sourceNode,
                                                   time + 1, bob, amount));
                distanceFromBob[sourceNode] =
                    min(distanceFromBob[sourceNode],
                        distanceFromBob[adjacentNode] + 1);
            }
        }
        // Alice reaches the node first
        if (distanceFromBob[sourceNode] > time) maxIncome += amount[sourceNode];

        // Alice and Bob reach the node at the same time
        else if (distanceFromBob[sourceNode] == time)
            maxIncome += amount[sourceNode] / 2;

        // Return max income of leaf node
        if (maxChild == INT_MIN)
            return maxIncome;
        else
            return maxIncome + maxChild;
    }
};