class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            v.push_back(val);
            mp[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int it = mp[val];
            mp[v.back()] = mp[val];
            v[it] = v.back();
            v.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};