class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		map<string, int> m;
		for (auto &e : words) m[e]++;
		int each_word_len = words[0].size();
		int n = s.size();
		int sz = words.size();
		for (int i = 0; i <= n - (each_word_len * sz); ++i) {
			map<string, int> m2;
			for(int j = i; j < i+(each_word_len * sz); j += each_word_len){    
				string x = s.substr(j, each_word_len);
				if (!m.count(x)) break;
				m2[x]++;
				if (m2[x] > m[x]) break;
			}
				if (m == m2) ans.push_back(i);
		}
		return ans;
	}
};