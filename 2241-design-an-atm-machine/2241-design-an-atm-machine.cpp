#define ll long long int
class ATM {
public:
    unordered_map<int,int> mp;
    vector<ll> note;
    ATM() {
        note.resize(5,0);
        mp[0] = 20;
        mp[1] = 50;
        mp[2] = 100;
        mp[3] = 200;
        mp[4] = 500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i < banknotesCount.size();i++){
            note[i] += (ll)banknotesCount[i];
        }
    }
    
    bool checkWithdrawPossible(int amount){
        int n = 4;
        while(amount > 0 && n >= 0 ){
            ll x = min((ll)amount/mp[n],note[n]);
            amount -= x * mp[n];
            n--;
        }
        return amount == 0;
    }
    
    vector<int> withdraw(int amount) {
        
        if(checkWithdrawPossible(amount)){
            vector<int> v(5,0);
            
            int n = 4;
            while(amount > 0 && n >= 0){
                ll x = min((ll)amount/mp[n],note[n]);
                amount -= x * mp[n];
                if(x != 0){
                    v[n] = x;
                    note[n] -= x;
                }
                n--;
            }
            return v;
        }else{
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */