class RecentCounter {
public:
    list<int> ll;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ll.push_back(t);
        while(!ll.empty() && ll.front() < t - 3000){
            ll.pop_front();
        }
        return ll.size();
    }
};