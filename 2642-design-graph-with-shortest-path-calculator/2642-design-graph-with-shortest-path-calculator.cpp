class Graph {
public:
    vector<vector<int>> adjMatrix;
    Graph(int n, vector<vector<int>>& edges) {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &e : edges)
            adjMatrix[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            adjMatrix[i][i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    adjMatrix[j][k] = min(adjMatrix[j][k],
                                           adjMatrix[j][i] + adjMatrix[i][k]);
    }
    
    void addEdge(vector<int> edge) {
        int n = adjMatrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = min(adjMatrix[i][j], 
                                       adjMatrix[i][edge[0]] +
                                       adjMatrix[edge[1]][j] +
                                       edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        if (adjMatrix[node1][node2] == 1e9) 
            return -1;
        return adjMatrix[node1][node2];
    }
};