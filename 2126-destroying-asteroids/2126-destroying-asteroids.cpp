class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int sum = mass;
        for (auto v : asteroids) {
            if (sum < v) return false;
            sum += v;
            if (sum > 1e5) break;
        }
        return true;
    }
};