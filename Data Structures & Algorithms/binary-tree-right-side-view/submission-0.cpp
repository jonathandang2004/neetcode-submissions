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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<int, TreeNode*>> q;
        int levelToAdd = 0;
        q.push({0, root});
        while (!q.empty()) {
            auto [level, node] = q.front();
            q.pop();
            if (!node) continue;
            if (level == levelToAdd) {
                ++levelToAdd;
                ans.push_back(node->val);
            }
            q.push({level + 1, node->right});
            q.push({level + 1, node->left});
        }
        return ans;
    }
};
