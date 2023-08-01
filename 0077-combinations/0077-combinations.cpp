class Solution {
public:
    vector<vector<int>> v;
    void combineUtil(int x,int n,int k,vector<int> &temp){
        if(k==0){
            v.push_back(temp);
        }else{
            for(int i=x;i<=n;i++){
                temp.push_back(i);
                combineUtil(i+1,n,k-1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        combineUtil(1,n,k,temp);
        return v;
    }
};