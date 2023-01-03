class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        
        vector<bool> v(1001, true);
        
        v[1] = false;
        for(int i=4;i<=1000;i += 2){
            v[i] = false;
        }
        for(int i = 3; i * i <= 1000; i+=2){
            for(int j = i * i; j <= 1000; j+=i){
                v[j] = false;
            }
        }
        
        for(auto it : nums){
            int count = 0;
            
            for(int i=1;i*i<=it;i++){
                if(it % i == 0){
                    if(v[i]){
                        st.insert(i);
                    }
                    if(it % (it/i) == 0 && v[it/i]){
                        st.insert(it/i);
                    }
                }
            }
        }
        return st.size();
    }
};