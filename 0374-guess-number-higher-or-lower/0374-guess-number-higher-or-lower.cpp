/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while(low <= high) {
            int pick = low + (high - low) / 2;
            int g = guess(pick);
            if (g == 0) return pick;

            if (g == 1) low = pick + 1;
            else high = pick - 1;
        }

        return -1;
    }
};