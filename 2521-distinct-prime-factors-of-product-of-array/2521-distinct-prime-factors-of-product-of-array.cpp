class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        
        vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        
        for(auto it : nums){
            
            for(auto i : v){
                if(it % i == 0){
                    st.insert(i);
                    
                    while(it % i == 0){
                        it = it/i;
                    }
                }
            }
            if(it != 1){
                st.insert(it);
            }
        }
        return st.size();
    }
};