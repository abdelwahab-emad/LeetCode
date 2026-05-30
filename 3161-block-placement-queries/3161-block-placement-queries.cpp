#include <bits/stdc++.h>
using namespace std;

struct Node{
    int mi;
    Node(){
        mi = 0;
    }
    Node(int x){
        mi = x;
    }
    void change(int x){
        mi = x;
    }
};

struct SegTree{
    int tree_size;
    vector<Node> SegData;

    SegTree(int n){
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        SegData.assign(2 * tree_size, Node());
    }

    Node merge(Node &lf, Node &ri){
        Node ans;
        ans.mi = max(lf.mi, ri.mi);
        return ans;
    }

    void inti(vector<int> &v, int ni, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)v.size())
                SegData[ni] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        inti(v, 2 * ni + 1, lx, mid);
        inti(v, 2 * ni + 2, mid, rx);

        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void inti(vector<int> &v){
        inti(v, 0, 0, tree_size);
    }

    void set(int idx, int val, int ni, int lx, int rx){
        if(rx - lx == 1){
            SegData[ni].change(val);
            return;
        }

        int mid = (lx + rx) / 2;

        if(idx < mid)
            set(idx, val, 2 * ni + 1, lx, mid);
        else
            set(idx, val, 2 * ni + 2, mid, rx);

        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void set(int idx, int val){
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx){
        if(lx >= l && rx <= r)
            return SegData[ni];

        if(lx >= r || rx <= l)
            return Node();

        int mid = (lx + rx) / 2;

        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);

        return merge(lf, ri);
    }

    int get(int l, int r){
        return get(l, r, 0, 0, tree_size).mi;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;
        for (auto &q : queries)
            mx = max(mx, q[1]);
        int x = mx + 1;
        set<int> obs;
        obs.insert(0);
        obs.insert(x);
        vector<multiset<int>> gapsEndAt(x + 1);
        SegTree seg(x + 1);
        auto applyPoint = [&](int r) {
            int v = gapsEndAt[r].empty() ? 0 : *gapsEndAt[r].rbegin();
            seg.set(r, v);
        };

        gapsEndAt[x].insert(x);
        applyPoint(x);

        vector<bool> res;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int p = q[1];

                auto it = obs.lower_bound(p);

                int b = *it;
                int a = *prev(it);

                auto &msB = gapsEndAt[b];
                msB.erase(msB.find(b - a));
                applyPoint(b);

                gapsEndAt[p].insert(p - a);
                applyPoint(p);

                gapsEndAt[b].insert(b - p);
                applyPoint(b);

                obs.insert(p);
            } else {
                int x = q[1];
                int sz = q[2];
                int bestFullyInside = seg.get(0, x + 1);
                int pred = *prev(obs.upper_bound(x));
                int tail = x - pred;
                int best = max(bestFullyInside, tail);
                res.push_back(best >= sz);
            }
        }
        return res;
    }
};