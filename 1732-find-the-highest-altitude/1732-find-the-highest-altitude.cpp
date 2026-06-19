class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, mx = 0;
        for (auto val : gain) {
            cur += val;
            mx = max(mx, cur);
        }
        return mx;
    }
};