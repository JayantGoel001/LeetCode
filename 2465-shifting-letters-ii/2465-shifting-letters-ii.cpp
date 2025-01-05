class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(
            n, 0);  // Initialize a difference array with all elements set to 0.

        for (auto shift : shifts) {
            if (shift[2] == 1) {        // If direction is forward (1):
                diffArray[shift[0]]++;  // Increment at the start index to
                                        // indicate a forward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]--;  // Decrement at the end+1 index to stop the
                                     // effect of the shift.
                }
            } else {                    // If direction is backward (0):
                diffArray[shift[0]]--;  // Decrement at the start index to
                                        // indicate a backward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]++;  // Increment at the end+1 index to stop the
                                     // effect of the shift.
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            if (numberOfShifts < 0)
                numberOfShifts +=
                    26;  // Ensure `numberOfShifts` is non-negative.

            // Calculate the new character by shifting `s[i]`
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};