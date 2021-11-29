class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, set<int>> dict;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                dict[accounts[i][j]].insert(i);
            }
        }
        vector<int> groups;
        for (int i = 0; i < accounts.size(); i++) groups.emplace_back(i);
        for (const auto& p : dict) {
            int root = numeric_limits<int>::max();
            for (const auto& i : p.second) root = min(root, get_root(groups, i));
            for (const auto& i : p.second) update_root(groups, i, root);
        }
        map<int, set<string>> hashed_accounts;
        for (int i = 0; i < groups.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                hashed_accounts[get_root(groups, i)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> result;
        for (const auto& p : hashed_accounts) {
            result.emplace_back();
            result.back().emplace_back(accounts[p.first].front());
            for (const auto& email : p.second) result.back().emplace_back(email);
        }
        return result;
    }

    void update_root(vector<int>& groups, int current, int root) {
        while (groups[current] != current) {
            auto temp = current;
            current = groups[current];
            groups[temp] = root;
        }
        groups[current] = root;
    }
    
    int get_root(const vector<int>& groups, int index) {
        while (groups[index] != index) index = groups[index];
        return index;
    }
};