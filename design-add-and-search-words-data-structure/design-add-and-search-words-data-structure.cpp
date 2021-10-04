class Node{
  public:
    unordered_map<char,Node*> mp;
    bool isEnd;
    
    Node(){
        isEnd = false;
    }
};
class WordDictionary {
public:
    Node *head;
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node *temp = head;
        for(auto it : word){
            if(temp->mp[it] == nullptr){
                temp->mp[it] = new Node();
            }
            temp = temp->mp[it];
        }
        temp->isEnd = true;
    }
    bool searchUtil(string &word,int x,Node *temp){
        if(!temp){
            return false;
        }
        if(x == word.size()){
            return temp->isEnd;
        }
        if(word[x] != '.'){
            if(temp->mp[word[x]] == nullptr){
                return false;
            }else{
                return searchUtil(word,x+1,temp->mp[word[x]]);
            }
        }else{
            for(auto it : temp->mp){
                bool res = searchUtil(word,x+1,it.second);
                if(res){
                    return res;
                }
            }
            return false;
        }
    }
    bool search(string word) {
        Node *temp = head;
        
        return searchUtil(word,0,temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */