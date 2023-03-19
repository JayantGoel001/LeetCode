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
        if(x == word.size()){
            return temp && temp->isEnd;
        }
        if(word[x] == '.'){
            for(int j=0;j<26;j++){
                if(temp->v[j] && find(word, temp->v[j], x + 1)){
                    return true;
                }
            }
            return false;
        }else{
            if(!temp->v[word[x] - 'a']){
                return false;
            }else{
                return find(word, temp->v[word[x] - 'a'], x + 1);
            }
        }
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        return find(word, temp, 0);
    }
};