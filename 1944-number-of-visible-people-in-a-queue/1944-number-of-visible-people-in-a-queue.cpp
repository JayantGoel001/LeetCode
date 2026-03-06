class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        stack <int> st;

        vector<int> result (heights.size(),0);

        for(int i=heights.size()-1; i>=0; i--){
            if(st.empty()){
                st.push(heights[i]);
                result[i]=0;
            }else{
                int count =0;
                while(!st.empty() && st.top()<=heights[i]){
                    st.pop();
                    count++;
                }
                if(!st.empty()){
                    result[i]=count+1;
                }else{
                    result[i]=count;
                }
                st.push(heights[i]);
            }
        }
        return result;
    }
};