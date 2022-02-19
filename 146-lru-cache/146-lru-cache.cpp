#define pii pair<int,int>
class LRUCache {
private:
    unordered_map<int,list<pii>::iterator> mp;
    list<pii> ll;
    int cap;
    
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            int value = it->second;
            
            ll.erase(it);
            
            ll.push_front({key,value});
            mp[key] = ll.begin();
            
            return value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            ll.erase(it);
        }else{
            if(mp.size() == this->cap){
                int key = ll.back().first;
                ll.pop_back();
                mp.erase(key);
            }
        }
        ll.push_front({key,value});
        mp[key] = ll.begin();
    }
};