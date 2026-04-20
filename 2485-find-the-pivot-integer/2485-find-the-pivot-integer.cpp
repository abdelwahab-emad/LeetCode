class Solution {
    long long get_sum(int val) { return val * (val + 1) / 2; }

public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; x++) {
            long long left = get_sum(x);
            long long right = get_sum(n) - get_sum(x - 1);
            if (left == right) {
                return x;
            }
        }
        return -1;
    }
};