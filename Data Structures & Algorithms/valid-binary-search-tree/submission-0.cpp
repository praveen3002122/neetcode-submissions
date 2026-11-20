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
    bool rec(TreeNode* root, long long mini, long long maxi) {
        if (root == nullptr) return true;

        if (root->val <= mini || root->val >= maxi)
            return false;

        bool left = rec(root->left, mini, root->val);
        bool right = rec(root->right, root->val, maxi);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return rec(root, LLONG_MIN, LLONG_MAX);
    }
};
