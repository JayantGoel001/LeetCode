class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v;
        int size = original.size();
        if(m*n == size){
            for(int i=0;i<size;i++){
                if(i%n == 0){
                    v.push_back({});
                }
                v[i/n].push_back(original[i]);
            }
        }
        return v;
    }
};