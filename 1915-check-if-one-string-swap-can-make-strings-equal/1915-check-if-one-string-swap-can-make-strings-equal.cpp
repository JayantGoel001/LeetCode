class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two
                // strings equal
                if (numDiffs > 2)
                    return false;
                else if (numDiffs == 1) {
                    // store the index of first difference
                    firstIndexDiff = i;
                } else {
                    // store the index of second difference
                    secondIndexDiff = i;
                }
            }
        }
        // check if swap is possible
        return s1[firstIndexDiff] == s2[secondIndexDiff] &&
               s1[secondIndexDiff] == s2[firstIndexDiff];
    }
};