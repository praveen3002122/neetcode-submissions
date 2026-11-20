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
    int idx =0;
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int st, int end){
        if(st>end) return nullptr;
        int val = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(val);

        int pos = st;
        while(inorder[pos]!=val){
            pos++;
        }
        root->left = rec(preorder, inorder,st,pos-1);
        root->right = rec(preorder, inorder, pos+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder, inorder, 0,inorder.size()-1);
    }
};
