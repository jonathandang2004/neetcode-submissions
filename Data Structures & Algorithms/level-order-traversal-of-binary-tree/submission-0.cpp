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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int, TreeNode*>> bfs;
        bfs.push({0, root});
        while (!bfs.empty()) {
            auto [index, node] = bfs.front();
            bfs.pop();
            if (node == nullptr) continue;
            // cout << index << " " << node->val << endl;
            if (index >= ans.size()) {
                ans.push_back({node->val});
            } else {
                ans[index].push_back(node->val);
            }
            bfs.push({index + 1, node->left});
            bfs.push({index + 1, node->right});

        }

        
        return ans;
    }

    // void traverse(vector<vector<int>>& ans, TreeNode* root, int level) {
    //     if (!root) {
    //         return;
    //     }
    //     if (ans.size() >= level) {
    //         vector.push_back({root->val});
    //     }

    //     traverse
    // }
};
