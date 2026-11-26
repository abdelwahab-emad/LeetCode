class Solution {
public:
    bool canAliceWin(int n) {
        bool f = false;
        int x = 10;
        while (n >= 0) {
            n -= x;
            if (n < 0) return f;
            f = !f;
            --x;
        }
        return f;
    }
};