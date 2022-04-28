class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(),-1);
        unordered_map<int, int> m;
        set<int> zero;
        for(int i =0; i < rains.size(); ++i){
            if(rains[i] == 0){
                zero.insert(i);
                res[i] = 1;
            }else{
                if(m.count(rains[i])){
                    int lastIndex = m[rains[i]];
                    auto zeroIndex = zero.upper_bound(lastIndex);
                    if(zeroIndex == zero.end()){
                        return {};
                    }
                    res[*zeroIndex] = rains[i];
                    zero.erase(zeroIndex);
                }
                m[rains[i]] = i;
            }
        }
        return res;
    }
};