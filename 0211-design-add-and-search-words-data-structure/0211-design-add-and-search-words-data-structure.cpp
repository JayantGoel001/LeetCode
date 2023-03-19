class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> v;
    
    TrieNode(){
        isEnd = false;
        v.resize(26, nullptr);
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp = root;
        for(auto it : word){
            if(!temp->v[it - 'a']){
                temp->v[it - 'a'] = new TrieNode();
            }
            temp = temp->v[it - 'a'];
        }
        temp->isEnd = true;
    }
    bool find(string &word, TrieNode *temp, int x){
        if(!temp){
            return false;
        }
        for(int i=x;i<word.size();i++){
            if(word[i] == '.'){
                bool found = false;
                for(int j=0;j<26;j++){
                    if(find(word, temp->v[j], i + 1)){
                        found = true;
                        return true;
                    }
                }
                if(!found){
                    return false;
                }
            }else{
                if(!temp->v[word[i] - 'a']){
                    return false;
                }
                temp = temp->v[word[i] - 'a'];
            }
        }
        return temp && temp->isEnd;
    }
    
    bool search(string word) {
        return find(word, root, 0);
    }
};