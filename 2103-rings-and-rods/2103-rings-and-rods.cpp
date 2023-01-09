class Solution {
public:
    int countPoints(string rings) {
        vector<unordered_set<char>> v(10);
        
        for(int i=1;i<rings.size();i+=2){
            v[rings[i] - '0'].insert(rings[i-1]);
        }
        
        int count = 0;
        for(auto it : v){
            count += it.size() == 3;
        }
        return count;
    }
};