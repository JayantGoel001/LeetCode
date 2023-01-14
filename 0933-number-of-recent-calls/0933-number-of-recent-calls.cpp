class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        return v.end() - lower_bound(v.begin(), v.end(), t - 3000);
    }
};