class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ans = 1;
        long long mx = LLONG_MIN;
        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (sum > mx) {
                mx = sum;
                ans = level;
            }

            level++;
        }
        return ans;
    }
};
