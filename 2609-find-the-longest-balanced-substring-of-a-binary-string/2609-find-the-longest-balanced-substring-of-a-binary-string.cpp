class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxi = 0;
        int z = 0;
        int o = 0;
        
        for(auto it : s){
            if(it == '0'){
                if(o){
                    z = 0;
                    o = 0;
                }
                z++;
            }else{
                if(!z){
                    continue;
                }
                o++;
            }
            
            maxi = max(maxi, min(z, o) * 2);
        }
        return maxi;
    }
};