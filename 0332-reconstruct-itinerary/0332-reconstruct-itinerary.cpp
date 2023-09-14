class Solution {
public:
    
    map<string, multiset<string>> mp;
    vector<string> result;

    void solve(string s){
         while(mp[s].size() != 0){
              string next = *mp[s].begin();
              mp[s].erase(mp[s].begin());
              solve(next);
         }
         result.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
           for(auto it: tickets){
               mp[it[0]].insert(it[1]);
           }
           solve("JFK");

           reverse(result.begin(), result.end());
           return result;
    }
};