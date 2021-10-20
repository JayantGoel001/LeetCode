class Solution {
public:
    map<int,string> mp;
    int x = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp[x] = longUrl;
        return to_string(x++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));