class Solution {
public:
    void convertNumberToChars(vector<char> &chars, int group, int &k){
        stack<char> st;
        while(group){
            st.push('0' + group%10);
            group/=10;
        }
        while(!st.empty()){
            chars[k++] = st.top();
            st.pop();
        }
    }
    int compress(vector<char>& chars) {
        int group = 0;
        char ch = chars[0];
        int k = 0;
        for(auto it : chars){
            if(it != ch){
                chars[k++] = ch;
                if(group > 1){
                    convertNumberToChars(chars, group, k);
                }
                ch = it;
                group = 1;
            }else{
                group++;
            }
        }
        chars[k++] = ch;
        if(group > 1){
            convertNumberToChars(chars, group, k);
        }
        return k;
    }
};