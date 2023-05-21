class Solution {
public:
    int uf_find(int i, vector<int>& nodes) {
  if (nodes[i] <= 0) return i;
  else return nodes[i] = uf_find(nodes[i], nodes);
}
int uf_union(int i, int j, vector<int>& nodes) {
  auto pi = uf_find(i, nodes), pj = uf_find(j, nodes);
  if (pi == pj) return 0;
  if (nodes[pi] > nodes[pj]) swap(pi, pj);
  nodes[pi] += min(-1, nodes[pj]);
  nodes[pj] = pi;
  return -nodes[pi];
}
int shortestBridge(vector<vector<int>> &A) {
  int sz = A.size();
  vector<int> nodes(sz * sz + 1);
  list<pair<int, int>> edges;
  for (auto i = 0; i < sz; ++i)
    for (auto j = 0; j < sz; ++j) {
      auto idx = i * sz + j + 1;
      if (A[i][j]) nodes[idx] = -1;
      if (j > 0) {
        if (A[i][j] && A[i][j - 1]) uf_union(idx - 1, idx, nodes);
        else edges.push_back({ idx - 1, idx });
      }
      if (i > 0) {
        if (A[i][j] && A[i - 1][j]) uf_union(idx - sz, idx, nodes);
        else edges.push_back({ idx - sz, idx });
      }
    }

  for (auto step = 1; ; ++step) {
    vector<pair<int, int>> merge_list;
    for (auto it = edges.begin(); it != edges.end(); ) {
      if (nodes[it->first] == 0 && nodes[it->second] == 0) ++it;
      else {
        if (nodes[it->first] != 0 && nodes[it->second] != 0) {
          if (uf_find(it->first, nodes) != uf_find(it->second, nodes)) return (step - 1) * 2;
        }
        merge_list.push_back({ it->first, it->second });
        edges.erase(it++);
      }
    }
    for (auto p : merge_list) {
      if (nodes[p.first] != 0 && nodes[p.second] != 0) {
        if (uf_find(p.first, nodes) != uf_find(p.second, nodes)) return step * 2 - 1;
      }
      uf_union(p.first, p.second, nodes);
    }
  }
}
};