// copied from Editorial
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initialize the array to store the result of each sub-problem
        int count[corridor.length() + 1][3];

        // Base cases
        count[corridor.length()][0] = 0;
        count[corridor.length()][1] = 0;
        count[corridor.length()][2] = 1;

        // Fill the array in a bottom-up fashion
        for (int index = corridor.length() - 1; index >= 0; index--) {
            if (corridor[index] == 'S') {
                count[index][0] = count[index + 1][1];
                count[index][1] = count[index + 1][2];
                count[index][2] = count[index + 1][1];
            } else {
                count[index][0] = count[index + 1][0];
                count[index][1] = count[index + 1][1];
                count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
            }
        }

        // Return the result
        return count[0][0];
    }
};