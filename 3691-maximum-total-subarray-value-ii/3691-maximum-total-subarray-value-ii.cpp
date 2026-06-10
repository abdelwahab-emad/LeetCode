class Solution {
public:
    struct Node {
        long long mn, mx;

        Node() {
            mn = 1e18;
            mx = -1e18;
        }

        Node(long long x) {
            mn = mx = x;
        }
    };

    struct SparseTable {
        vector<vector<Node>> SP;
        int n;

        SparseTable(const vector<int>& v) {
            n = v.size();

            int lg = __lg(n) + 1;
            SP.assign(lg, vector<Node>(n));

            for (int i = 0; i < n; i++) {
                SP[0][i] = Node(v[i]);
            }

            for (int k = 1; (1 << k) <= n; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    SP[k][i] = merge(
                        SP[k - 1][i],
                        SP[k - 1][i + (1 << (k - 1))]
                    );
                }
            }
        }

        Node merge(const Node& a, const Node& b) {
            Node res;
            res.mn = min(a.mn, b.mn);
            res.mx = max(a.mx, b.mx);
            return res;
        }

        Node query(int l, int r) {
            int k = __lg(r - l + 1);
            return merge(
                SP[k][l],
                SP[k][r - (1 << k) + 1]
            );
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable sol(nums);
        auto get = [&](int l, int r) {
            Node cur = sol.query(l, r);
            return cur.mx - cur.mn;
        };
        priority_queue<pair<long long, pair<int, int>>> pq;
        for (int l = 0; l < n; l++) {
            pq.push({get(l, n - 1), {l, n - 1}});
        }
        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();
            long long val = cur.first;
            int l = cur.second.first;
            int r = cur.second.second;
            ans += val;
            if (r > l) {
                pq.push({get(l, r - 1),{l, r - 1}});
            }
        }
        return ans;
    }
};