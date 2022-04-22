#define pii pair<int,int>
class MyHashMap {
public:
    const static int size = 1000;
    list<pii> ll[size];
    
    int hash(int key){
        return key%size;
    }
    
    MyHashMap() {}
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        ll[h].push_back({key,value});
    }
    
    int get(int key) {
        int h = hash(key);
        list<pii> l = ll[h];
        
        for(auto it : l){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        list<pii> l = ll[h];
        
        for(auto it : l){
            if(it.first == key){
                ll[h].remove(it);
                break;
            }
        }
    }
};