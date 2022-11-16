/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n, mid, guessNumber;
        while (start <= end) {
            mid = start + (end - start) / 2;    // optimize it
            guessNumber = guess(mid);
            if (guessNumber == 0) {
                return mid;
            } else if (guessNumber < 0) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};