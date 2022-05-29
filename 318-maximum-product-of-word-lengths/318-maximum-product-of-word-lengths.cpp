class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        int ar[n];
        for(int i=0;i<n;i++){
            ar[i] = 0;
        }
        
        for(int i=0;i < n;i++){
            for(auto ch : words[i]){
                ar[i] |= 1<<(ch - 'a');
            }    
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!(ar[i] & ar[j])){
                    maxi = max(maxi,(int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return maxi;
    }
};