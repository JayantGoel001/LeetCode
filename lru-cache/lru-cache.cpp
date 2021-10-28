#define pii pair<int,int>
class LRUCache {
public:
    list<pii> ll;
    unordered_map<int,list<pii>::iterator> mp;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;       
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            pii el = *it;
            ll.push_front(*it);
            ll.erase(it);
            mp[key] = ll.begin();
            return el.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(ll.size() == capacity){
                pii el = ll.back();
                ll.pop_back();
                mp.erase(el.first);
            }
        }else{
            auto it = mp[key];
            ll.erase(it);
        }
        ll.push_front({key,value});
        mp[key] = ll.begin();
    }
};
