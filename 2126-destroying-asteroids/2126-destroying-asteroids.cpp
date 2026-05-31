class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long x = mass;
        for(auto v : asteroids) {
            if (v <= x) x += v;
            else {
                return false;
            }
        }
        return true;
    }
};