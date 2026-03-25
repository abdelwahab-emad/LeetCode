class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;

        //dpA : ABC all different
        //dpB : ABA two same
        long long dpA = 6, dpB = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;

            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
