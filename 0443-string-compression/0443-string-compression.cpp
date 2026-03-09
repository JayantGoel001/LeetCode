class Solution {
public:
    void update(vector<char>& chars, int &total, int curr, int &start, int index) {
        chars[start++] = chars[index - 1];
        total++;

        if (curr == 1) {
            return;
        }
        
        int x = start;
        while (curr > 0) {
            chars[start++] = '0' + curr % 10;
            curr /= 10;
            total++;
        }
        reverse(chars.begin() + x, chars.begin() + start);
    }
    int compress(vector<char>& chars) {
        int total = 0;
        int curr = 0;
        int start = 0;
        int i;
        for(i=0;i<chars.size();i++) {
            if (i == 0 || chars[i] == chars[i - 1]) {
                curr++;
            } else {
                update(chars, total, curr, start, i);
                curr = 1;
            }
        }

        update(chars, total, curr, start, chars.size());
        return total;
    }
};