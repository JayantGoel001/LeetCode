class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        int count = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            int size = q.size();
            
            count++;
            while(size--){
                string top = q.front();
                q.pop();
                
                if(top == endWord){
                    return count;
                }
                st.erase(top);
                for(int i=0;i<top.size();i++){
                    string x = top;
                    for(int k='a';k<='z';k++){
                        x[i] = k;
                        
                        if(st.find(x) != st.end()){
                            q.push(x);
                        }
                    }
                }
            }
        }
        return 0;
    }
};