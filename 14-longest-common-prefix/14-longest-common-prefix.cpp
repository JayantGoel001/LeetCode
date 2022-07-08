class Trie{
    public:
    bool isEnd;
    unordered_map<char,Trie*> mp;
    Trie(){
        this->isEnd = false;
    }
};
class Solution {
public:
    void insert(Trie *trie,string str){
         for(auto it : str){
             if(trie->mp.find(it) == trie->mp.end()){
                 trie->mp[it] = new Trie();
             }
             trie = trie->mp[it];
         }
         trie->isEnd = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie();   
        for(int i=0;i<strs.size();i++){
            insert(trie,strs[i]);
        }
        string str = "";
        while(trie && trie->mp.size()==1 && trie->isEnd == false){
            char it = trie->mp.begin()->first;
            str += it;

            trie = trie->mp[it];
        }
        return str;
    }
};