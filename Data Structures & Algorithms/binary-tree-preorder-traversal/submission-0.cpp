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
void rec(TreeNode* temp, vector<int>&ans){
    if(temp==nullptr) return;

    ans.push_back(temp->val);
    rec(temp->left,ans);
    rec(temp->right,ans);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        rec(root, ans);

        return ans;
    }
};