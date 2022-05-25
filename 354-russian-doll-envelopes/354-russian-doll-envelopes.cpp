class Solution {
public:    
    vector<int> lis;    
    int f_search (int val) {
        int s = 0;
        int e = lis.size()-1;
        int m = (s+e)/2;
        while(s < e) {            
            if(lis[m] < val) s = m + 1;
            else e = m;            
            m = (s+e) / 2;
        }
        return s;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &o1, vector<int> &o2){
            if(o1[0] == o2[0]) return o1[1] > o2[1];
            return o1[0] < o2[0];
        });
        
        lis.push_back(0);
        int loc = 0;
        for (vector<int> node : envelopes) {            
            if(lis.back() < node[1]) lis.push_back(node[1]);
            else {
                loc = f_search(node[1]);                
                lis[loc] = node[1];           
            }            
        }
        
        return lis.size() - 1;
    }    
};