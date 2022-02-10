#define pii pair<int,int>
class LRUCache {
public:
    int cap;
    list<pii> ll;
    unordered_map<int,list<pii>::iterator> mp;
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        auto it = mp[key];
        int value = it->second;
        ll.erase(it);
        ll.push_front({key,value});
        mp[key] = ll.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            ll.erase(it);
        }else{
            if(ll.size() == this->cap){
                pii el = ll.back();
                mp.erase(el.first);
                ll.pop_back();
            }
        }
        ll.push_front({key,value});
        mp[key] = ll.begin();
    }
};
