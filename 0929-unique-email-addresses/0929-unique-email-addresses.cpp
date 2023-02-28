class Solution {
public:
    string formatEmail(string &email){
        string str = "";
        bool flag = false;
        bool flagat = false;
        for(auto it : email){
            if(flag){
                if(it == '@'){
                    flag = false;
                }else{
                    continue;
                }
            }
            if(it == '@'){
                flagat = true;
            }
            if(flagat){
                str += it;
                continue;
            }
            if(it == '+'){
                flag = true;
            }else if(it != '.'){
                str += it;
            }
        }
        return str;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(auto email : emails){
            st.insert(formatEmail(email));
        }
        return st.size();
    }
};