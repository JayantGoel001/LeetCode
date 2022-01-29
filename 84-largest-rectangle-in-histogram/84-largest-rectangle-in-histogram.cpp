class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int top = st.top();
                st.pop();
                maxArea = max(maxArea, heights[top] * (st.empty()? i : i - st.top() - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            maxArea = max(maxArea, heights[top] * (st.empty() ? n : n - st.top() - 1));
        }
        return maxArea;
    }
};