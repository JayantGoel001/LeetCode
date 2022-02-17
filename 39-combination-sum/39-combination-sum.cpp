class Solution {
public:
    vector<vector<int>> v;
    
    void generateComb(vector<int> &can,int target,vector<int> &temp,int x = 0){
        if(target < 0){
            return;
        }
        if(target == 0){
            v.push_back(temp);
        }else{
            for(int i=x;i<can.size();i++){
                temp.push_back(can[i]);
                
                generateComb(can,target - can[i],temp,i);
                
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        generateComb(candidates,target,temp);
        return v;
    }
};