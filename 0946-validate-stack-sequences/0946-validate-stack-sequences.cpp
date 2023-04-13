class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int start = 0;
        stack<int> st;
        
        for(auto it : pushed){
            st.push(it);
            
            while(!st.empty() && start < popped.size() && st.top() == popped[start]){
                st.pop();
                start++;
            }
        }
        
        return st.empty() && start == popped.size();
    }
};