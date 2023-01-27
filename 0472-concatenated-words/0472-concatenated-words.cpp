class Trie{
public:
    bool isEnd;
    vector<Trie*> children;
    
    Trie(){
        isEnd = false;
        children.resize(26, nullptr);
    }
};
class Solution {
public:
    bool find(Trie *root, string &word, int pos){
        Trie *temp = root;
        for(int i = pos; i < word.size(); i++){
            if(temp == nullptr){
                return false;
            }
            if(temp->isEnd){
                bool res = find(root, word, i);
                if(res){
                    return res;
                }
            }
            temp = temp->children[word[i] - 'a'];
        }
        return temp && temp->isEnd;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root = new Trie();
        
        Trie *temp = nullptr;
        
        for(auto word : words){
            temp = root;
            for(auto it : word){
                if(temp->children[it - 'a'] == nullptr){
                    temp->children[it - 'a'] = new Trie();
                }
                temp = temp->children[it - 'a'];
            }
            temp->isEnd = true;
        }
        vector<string> v;
        for(auto word : words){
            temp = root;
            for(int i=0;i<word.size();i++){
                if(temp->isEnd){
                    if(find(root, word, i)){
                        v.push_back(word);
                        break;
                    }
                }
                temp = temp->children[word[i] - 'a'];
            }
        }
        return v;
    }
};