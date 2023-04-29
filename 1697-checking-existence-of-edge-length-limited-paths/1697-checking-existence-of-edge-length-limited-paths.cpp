class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);

        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
    }

    bool areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};


class Solution {
public:
    // Sort in increasing order based on the 3rd element of the array.
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind uf(n);
        int queriesCount = queries.size();
        vector<bool> answer(queriesCount);

        // Store original indices with all queries.
        vector<vector<int>> queriesWithIndex(queriesCount);
        for (int i = 0; i < queriesCount; ++i) {
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }

        int edgesIndex = 0;

        // Sort all edges in increasing order of their edge weights.
        sort(edgeList.begin(), edgeList.end(), compare);
        // Sort all queries in increasing order of the limit of edge allowed.
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

        // Iterate on each query one by one.
        for (auto& query : queriesWithIndex) {
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int queryOriginalIndex = query[3];

            // We can attach all edges which satisfy the limit given by the query.
            while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit) {
                int node1 = edgeList[edgesIndex][0];
                int node2 = edgeList[edgesIndex][1];
                uf.join(node1, node2);
                edgesIndex += 1;
            }

            // If both nodes belong to the same component, it means we can reach them. 
            answer[queryOriginalIndex] = uf.areConnected(p, q);
        }

        return answer;
    }
};