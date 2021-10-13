class Solution {
public:
    vector<vector<int>> v;
    
    void generateSum(vector<int> &cand,int target,vector<int> &_v,int x=0) {
        if(target == 0){
            v.push_back(_v);
        }else if(target > 0){
            for(int i=x;i<cand.size();i++){
                _v.push_back(cand[i]);
                generateSum(cand,target - cand[i],_v,i);
                _v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> _v;
        generateSum(candidates,target,_v);
        return v;
    }
};