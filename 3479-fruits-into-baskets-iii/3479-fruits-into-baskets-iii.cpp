/**
IDEA: Square root decomposition on baskets and store the maximum on each block.
Update if maximum value on a block is >= fruit (0...n)
*/
class Solution {
public:

    void markVisited(int block, int fruit, vector<int> &baskets) {
        int n = baskets.size();
        int sq = sqrt(n) + 1;
        int st = block*sq, ed = (block+1)*sq;
        for (int j =  st; j < ed && j < n; j++) {
            if (baskets[j] >= fruit) {
                baskets[j] = 0;
                break;
            }
        }
        values[block] = 0;
        for (int j = st; j < ed && j < n; j++) {
            values[block] = max(values[block], baskets[j]);
        }
        return;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int sq = sqrt(n) + 1;
        values.resize(sq + 1,  0);
        for (int i = 0; i < n; i++) {
            int block = i / sq;
            values[block] = max(values[block], baskets[i]);
        }
        int found = 0;
        for (auto fruit : fruits) {
            for (int i = 0; i <= sq; i++) {
                if (values[i] >= fruit) {
                    markVisited(i, fruit, baskets);
                    found++;
                    break;
                }
            }
        }
        return n - found;
    }
private:
    vector<int> values;
};