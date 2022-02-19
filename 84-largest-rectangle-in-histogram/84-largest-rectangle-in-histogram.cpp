class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int maxi = 0;
        
        int i = 0;
        while(i < n){
            if(st.empty() || heights[st.top()] <= heights[i]){
                st.push(i++);
            }else{
                int top = st.top();
                st.pop();
                
                maxi = max(maxi,heights[top] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();

            maxi = max(maxi,heights[top] * (st.empty() ? i : i - st.top() - 1));
        }
        return maxi;
    }
};