class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> heap;
        
        for (int i = 0; i < dist.size(); i++) {
            heap.push((float) dist[i] / speed[i]);
        }

        int ans = 0;
        while (!heap.empty()) {
            if (heap.top() <= ans) {
                break;
            }
            
            ans++;
            heap.pop();
        }
        
        return ans;
    }
};