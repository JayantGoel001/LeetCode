class RecentCounter {
public:
    queue<int> ll;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ll.push(t);
        while(!ll.empty() && ll.front() < t - 3000){
            ll.pop();
        }
        return ll.size();
    }
};