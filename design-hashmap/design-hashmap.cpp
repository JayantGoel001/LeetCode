class MyHashMap {
public:
    vector<list<int>::iterator> v;
    list<int> ll;
    MyHashMap() : v(1000001,ll.end()){}
    
    void put(int key, int value) {
        ll.push_front(value);
        v[key] = ll.begin();
    }
    
    int get(int key) {
        if(v[key] != ll.end()){
            return *v[key];
        }
        return -1;
    }
    
    void remove(int key) {
        if(v[key] != ll.end()){
            ll.erase(v[key]);
            v[key] = ll.end();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */