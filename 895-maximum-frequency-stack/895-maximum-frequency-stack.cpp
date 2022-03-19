class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxi;
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;
        
        maxi = max(maxi,freq[val]);
        
        group[freq[val]].push(val);
    }
    
    int pop() {
        int top = group[maxi].top();
        group[maxi].pop();
        
        freq[top]--;
        
        if(group[maxi].size() == 0){
            maxi--;
        }
        return top;
    }
};