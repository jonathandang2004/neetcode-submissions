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
    vector<int> hi;
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return hi[k - 1];
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left);
        hi.push_back(root->val);
        traverse(root->right);
    }
};
