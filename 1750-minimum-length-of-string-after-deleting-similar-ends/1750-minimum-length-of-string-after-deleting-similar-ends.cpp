class Solution {
public:
    int minimumLength(string s) {
        return deleteSimilarEnds(s, 0, s.length() - 1);
    }
private:
    // Deletes similar ends and returns remaining length 
    int deleteSimilarEnds(string &s, int begin, int end) {
        // The ends differ or meet in the middle
        if (begin >= end || s[begin] != s[end]){
            return end - begin + 1;
        } else {
            char c = s[begin];

            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s[begin] == c)
                begin++;

            // Delete consecutive occurrences of c from suffix
            while (end > begin && s[end] == c)
                end--;

            return deleteSimilarEnds(s, begin, end); 
        }  
    }
};