class Solution {
public:
    //comparator to sort the vector in increasing order
    bool static cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])return a[1] > b[1]; //if the value is same, sorting in decreasing order
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), cmp);
        stack<int> st;  
        int cnt = 0;
        
        //iterating in reverse order as the last element will not follow the property
        for(int i = n-1; i >= 0; i--)
        {
            int ele = properties[i][1];
            //if stack is empty, pushing the value in the stack.
            if(st.empty())st.push(ele);
            //if the stack contains any value, keeping the larger value on the top,
            // as the larger value will satisfy the given property for any smaller element.
            else if(ele >= st.top())
            { 
                st.pop();
                st.push(ele);
            }
            // If the value is smaller, 
            else
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};