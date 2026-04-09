#include <vector>
#include <cmath>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n);
        vector<vector<vector<tuple<int, int, int>>>> bucket(B + 1, vector<vector<tuple<int, int, int>>>(B + 1));
        for (auto &qr : queries) {
            int l = qr[0], r = qr[1], k = qr[2], v = qr[3];
            if (k <= B) {
                bucket[k][l % k].push_back({l, r, v});
            }
        }

        for (int k = 1; k <= B; k++) {
            for (int rem = 0; rem < k; rem++) {
                if (bucket[k][rem].empty()) continue;

                int sz = (n - 1 - rem) / k + 1;
                vector<long long> diff(sz + 1, 1);

                for (auto &[l, r, v] : bucket[k][rem]) {
                    int L = (l - rem) / k;
                    int R = (r - rem) / k;
                    diff[L] = (diff[L] * v) % MOD;
                    if (R + 1 < sz) {
                        diff[R + 1] = (diff[R + 1] * modInverse(v)) % MOD;
                    }
                }

                long long mul = 1;
                for (int i = 0; i < sz; i++) {
                    mul = (mul * diff[i]) % MOD;
                    int idx = i * k + rem;
                    nums[idx] = (nums[idx] * mul) % MOD;
                }
            }
        }

        for (auto &qr : queries) {
            int l = qr[0], r = qr[1], k = qr[2], v = qr[3];
            if (k > B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (nums[idx] * (long long)v) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};