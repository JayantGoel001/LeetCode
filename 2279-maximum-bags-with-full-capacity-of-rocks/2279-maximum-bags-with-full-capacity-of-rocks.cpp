class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int count = 0;
        int n = capacity.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(capacity[i] - rocks[i]);
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++){
            if(add > 0){
                if(v[i] <= add){
                    add -= v[i];
                    count++;
                }else{
                    add = 0;
                }
            }else{
                break;
            }
        }
        return count;
    }
};