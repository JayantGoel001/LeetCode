class TopVotedCandidate {
public:
    map<int, int> m;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = persons.size(), lead = -1;
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            lead = ++count[persons[i]] >= count[lead] ? persons[i] : lead;
            m[times[i]] = lead;
        }
    }

    int q(int t) {
        return (--m.upper_bound(t))-> second;
    }
};