class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> frq(n + 1, 0), ans(n);
        for(int i = 0;i < n;i++) {
            frq[A[i]]++;
            frq[B[i]]++;
            ans[i] += (frq[A[i]] == 2);
            ans[i] += (frq[B[i]] == 2);
            ans[i] -= (A[i] == B[i]);
            if (i) ans[i] += ans[i - 1];
        }
        return ans;
    }
};