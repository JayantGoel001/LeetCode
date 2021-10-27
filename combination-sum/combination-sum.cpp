class Solution {
public:
    vector<vector<int>> v;
    void generateComb(vector<int> &comb,int target,vector<int> &_v,int n,int x = 0){
        if(target == 0){
            v.push_back(_v);
        }else if(target > 0){
            for(int i=x;i<n;i++){
                _v.push_back(comb[i]);
                generateComb(comb,target - comb[i],_v,n,i);
                _v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> _v;
        
        generateComb(cand,target,_v,cand.size());
        return v;
    }
};