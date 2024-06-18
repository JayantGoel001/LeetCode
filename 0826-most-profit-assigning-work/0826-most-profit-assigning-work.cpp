class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int N = profit.size(), res = 0, i = 0, best = 0;
        map<int, int> jobs;
        jobs[0] = 0;
        for (int j = 0; j < N; ++j)
            jobs[difficulty[j]] = max(jobs[difficulty[j]], profit[j]);
        for (auto &it: jobs)
            it.second = best = max(best, it.second);
        for (int & ability : worker)
            res += (--jobs.upper_bound(ability))->second;
        return res;
    }
};