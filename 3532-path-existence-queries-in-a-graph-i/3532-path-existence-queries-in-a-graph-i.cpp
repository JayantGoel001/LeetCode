class DSU{
    vector<int> parent;

public:
    DSU(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int parX = find(x);
        int parY = find(y);

        parent[parX] = parY;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        DSU dsu(n);

        pair<int, int> temp = pq.top();

        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            pq.pop();

            if(abs(temp.first - curr.first) <= maxDiff){
                dsu.merge(temp.second, curr.second);
            }

            temp = curr;
        }

        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(dsu.find(it[0]) == dsu.find(it[1]));
        }

        return sol;
    }
};