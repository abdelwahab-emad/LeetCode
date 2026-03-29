class Solution {
public:
    struct Node {
        int val;
        Node() { val = 0; }
        Node(int x) { val = x; }
        void change(int x) { val += x; }
    };

    struct SegTree {
        int tree_size;
        vector<Node> SegData;

        SegTree(int n) {
            tree_size = 1;
            while (tree_size < n)
                tree_size *= 2;
            SegData.assign(2 * tree_size, Node());
        }

        // change
        Node merge(Node& lf, Node& ri) {
            Node ans = Node();
            ans.val = lf.val + ri.val;
            return ans;
        }

        void inti(vector<int>& v, int ni, int lx, int rx) {
            if (rx - lx == 1) {
                if (lx < v.size())
                    SegData[ni] = Node(v[lx]);
                return;
            }

            int mid = (lx + rx) / 2;
            inti(v, 2 * ni + 1, lx, mid);
            inti(v, 2 * ni + 2, mid, rx);

            SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
        }
        void inti(vector<int>& v) { inti(v, 0, 0, tree_size); }
        void set(int idx, int val, int ni, int lx, int rx) {
            if (rx - lx == 1) {
                SegData[ni].change(val);
                return;
            }

            int mid = (rx + lx) / 2;
            if (idx < mid) {
                set(idx, val, 2 * ni + 1, lx, mid);
            } else {
                set(idx, val, 2 * ni + 2, mid, rx);
            }

            SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
        }

        void set(int idx, int val) { set(idx, val, 0, 0, tree_size); }

        Node get(int l, int r, int ni, int lx, int rx) {
            if (lx >= l and rx <= r) {
                return SegData[ni];
            }
            if (lx >= r or rx <= l) {
                return Node();
            }

            int mid = (rx + lx) / 2;
            Node lf = get(l, r, 2 * ni + 1, lx, mid);
            Node ri = get(l, r, 2 * ni + 2, mid, rx);

            return merge(lf, ri);
        }

        int get(int l, int r) { return get(l, r, 0, 0, tree_size).val; }
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        SegTree seg(1e5);
        int offset = 1e4;
        for(int i = 0;i < n;i++){
            seg.set(nums[i] + offset, 1);
        }
        vector<int> ans(n);
        for(int i = 0;i < n;i++){
            seg.set(nums[i] + offset, -1);
            ans[i] = seg.get(0, nums[i] + offset);
        }
        return ans;
    }
};