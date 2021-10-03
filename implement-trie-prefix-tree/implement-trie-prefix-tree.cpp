class Node{
  public:
    unordered_map<char,Node*> mp;
    bool isEnd;
    
    Node(){
        isEnd = false;
    }
};
class Trie {
public:
    Node *head;
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node *temp = head;
        for(auto it : word){
            if(temp->mp[it] == nullptr){
                temp->mp[it] = new Node();
            }
            temp = temp->mp[it];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node *temp = head;
        
        for(auto it : word){
            if(temp->mp[it] == nullptr){
                return false;
            }
            temp = temp->mp[it];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *temp = head;
        
        for(auto it : prefix){
            if(temp->mp[it] == nullptr){
                return false;
            }
            temp = temp->mp[it];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */