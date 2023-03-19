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
        for(int i=x;i<word.size();i++){
            if(word[i] == '.'){
                for(int j=0;j<26;j++){
                    if(temp->v[j] && find(word, temp->v[j], i + 1)){
                        return true;
                    }
                }
                return false;
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