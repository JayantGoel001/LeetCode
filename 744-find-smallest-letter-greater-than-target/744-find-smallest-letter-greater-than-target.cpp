class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return letters[(upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % letters.size()];
    }
};