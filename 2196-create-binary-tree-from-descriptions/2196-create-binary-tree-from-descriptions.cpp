/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        set<int> children;
        for (auto &d : descriptions) {
            int par = d[0], child = d[1], left = d[2];
            if (!mp.count(par)) mp[par] = new TreeNode(par);
            if (!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }
            if (left) mp[par]->left = mp[child];
            else mp[par]->right = mp[child];
            children.insert(child);
        }
        TreeNode* root = nullptr;
        for (auto &d : descriptions) {
            int par = d[0];
            if (!children.count(par)) {
                root = mp[par];
                break;
            }
        }
        return root;
    }
};