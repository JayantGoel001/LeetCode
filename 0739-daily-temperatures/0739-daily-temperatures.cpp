class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> v(temperatures.size(),0);
        for(int i = 0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};