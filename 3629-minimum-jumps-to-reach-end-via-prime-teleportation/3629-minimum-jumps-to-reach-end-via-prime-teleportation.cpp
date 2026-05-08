class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int MX = *max_element(nums.begin(), nums.end()) + 2;

        vector<bool> isPrime(MX + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MX; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<vector<int>> divPos(MX + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    divPos[d].push_back(i);

                    while (x % d == 0)
                        x /= d;
                }
            }

            if (x > 1)
                divPos[x].push_back(i);
        }

        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> usedPrime(MX + 1, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int step = dist[i];

            if (i == n - 1)
                return step;

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = step + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = step + 1;
                q.push(i + 1);
            }

            int p = nums[i];

            if (isPrime[p] && !usedPrime[p]) {
                usedPrime[p] = true;

                for (int nxt : divPos[p]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = step + 1;
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};