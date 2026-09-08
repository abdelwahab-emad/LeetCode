class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 1000 + 1);
    }
};