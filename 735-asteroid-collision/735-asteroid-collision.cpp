class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int size = asteroids.size();
        
        for(int i=0;i<size;i++){
            int it = asteroids[i];
            if(st.empty() || it>0 || st.back() < 0){
                st.push_back(it);
            }else if(-it > st.back()){
                st.pop_back();
                i--;
            }else if(-it == st.back()){
                st.pop_back();
            }
        }
        
        return st;
    }
};