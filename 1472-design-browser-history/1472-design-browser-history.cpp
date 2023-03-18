class BrowserHistory {
public:
    vector<string> v;
    int curr = 0;
    int size = 0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        curr++;
        if(v.size() > curr){
            v[curr] = url;
        }else{
            v.push_back(url);
        }
        size = curr;
    }
    
    string back(int steps) {
        curr = max(curr - steps, 0);
        return v[curr];
    }
    
    string forward(int steps) {
        curr = min(size, curr + steps);
        return v[curr];
    }
};