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
    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        // If either subtree is unbalanced
        if (l == -1 || r == -1) return -1;

        // Check height difference
        if (abs(l - r) > 1) return -1;

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};

