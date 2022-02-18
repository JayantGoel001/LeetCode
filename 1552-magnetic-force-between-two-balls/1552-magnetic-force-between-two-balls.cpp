class Solution {
public:
    
    bool isPossible(vector<int>& pos,int mid,int m){
        int count = 1;
        int last = pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i] - last >= mid){
                count++;
                last = pos[i];
            }
        }
        return count < m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        int n = position.size();
        int mini = 1;
        int maxi = position[n-1] - position[0];
        
        while(mini <= maxi){
            int mid = mini + (maxi - mini)/2;
            
            if(isPossible(position,mid,m)){
                maxi = mid - 1;
            }else{
                mini = mid + 1;
            }
        }
        return maxi;
    }
};