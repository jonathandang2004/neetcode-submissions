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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, -101, ans);
        return ans;
    }

    void dfs(TreeNode* root, int maxInPath, int& ans) {
        if (!root) return;
        int val = root->val;
        if (maxInPath <= val) {
            ++ans;
            maxInPath = val;
        }
        dfs(root->left, maxInPath, ans);
        dfs(root->right, maxInPath, ans);
    }
};
