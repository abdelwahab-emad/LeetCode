class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (auto c : costs) {
            if (c > coins) break;
            coins -= c;
            cnt++;
        }
        return cnt;
    }
};