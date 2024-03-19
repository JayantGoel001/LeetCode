class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        int count = 0;
        for(auto e : tasks){
            v[e - 'A']++;
            count = max(count, v[e - 'A']);
        }
        
        int ans = (count - 1) * (n + 1);
        for(auto e : v) if(e == count) ans++;
        return max((int)tasks.size(), ans);
    }
};