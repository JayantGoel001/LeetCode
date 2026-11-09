class Solution {
    struct Job {
        int at; // the time its server frees up
        int server;
        auto operator<=>(const Job&) const = default;
    };
    template <class T> using MinHeap = priority_queue<T, vector<T>, greater<>>;

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> turns(k);
        iota(turns.begin(), turns.end(),
             0); // at request 0, server x's next turn is x
        MinHeap<int> free(
            greater<>{},
            std::move(turns)); // each free server, keyed by its next turn

        MinHeap<Job> busy;
        vector<int> handled(k);
        for (int i = 0; i < ssize(arrival); ++i) {
            while (!busy.empty() &&
                   busy.top().at <= arrival[i]) { // done by the arrival
                int x = busy.top().server;
                busy.pop();
                free.push(i + (x - i % k + k) % k); // its first turn from i on
            }
            if (free.empty())
                continue; // none free: the request is dropped
            int x = free.top() % k;
            free.pop();
            busy.push({arrival[i] + load[i], x});
            ++handled[x];
        }

        int most = ranges::max(handled);
        vector<int> ans;
        for (int x = 0; x < k; ++x)
            if (handled[x] == most)
                ans.push_back(x);
        return ans;
    }
};