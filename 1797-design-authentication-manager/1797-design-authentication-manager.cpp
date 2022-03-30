class AuthenticationManager {
public:
    int ttl = 0;
    set<pair<int, string>> time_map;
    unordered_map<string, int> token_map;
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    void clean(int currentTime) {
        while(!time_map.empty() && begin(time_map)->first <= currentTime) {
            token_map.erase(begin(time_map)->second);
            time_map.erase(begin(time_map));
        }
    }
    void generate(string tokenId, int currentTime) {
        token_map[tokenId] = currentTime + ttl;
        time_map.insert({currentTime + ttl, tokenId});
    }
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        auto it = token_map.find(tokenId);
        if (it != end(token_map)) {
            time_map.erase({it->second, it->first});
            it->second = currentTime + ttl;
            time_map.insert({currentTime + ttl, tokenId});
        }
    }
    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        return token_map.size();
    }
};