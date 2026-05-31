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
private:
    bool ans = false;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        find(root, subRoot);
        return ans;
    }

    void find(TreeNode* root, TreeNode* subroot) {
        if (!root || !subroot) return;
        if (root->val == subroot->val) {
            bool thing = isSameTree(root, subroot);
            if (!ans) ans = thing;
        }
        find(root->left, subroot);
        find(root->right, subroot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};
