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
    bool isValidBST(TreeNode* root) {
        int min = -INT_MIN;
        bool notOrder = false;
        dfs(root, min, notOrder);
        return !notOrder;
    }
    // inorder traversal
    void dfs(TreeNode* root, int& min, bool& notOrder) {
        if (notOrder) return;
        if (!root) return;
        dfs(root->left, min, notOrder);
        if (root->val <= min) {
            notOrder = true;
            return;
        }
        else min = root->val;
        
        dfs(root->right, min, notOrder);
        return;
    }
};
