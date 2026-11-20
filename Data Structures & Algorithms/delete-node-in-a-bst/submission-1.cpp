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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

        if(key<root->val) root->left = deleteNode(root->left,key);
        else if (key>root->val) root->right = deleteNode(root->right,key);
        else{
            if(root->left ==nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //both exist

            TreeNode* temp1 = root->right;
            
            while(temp1->left!=nullptr){
                temp1 = temp1->left;
            }

            root->val = temp1->val;

            root->right = deleteNode(root->right,temp1->val);

        }
        return root;
    }
};