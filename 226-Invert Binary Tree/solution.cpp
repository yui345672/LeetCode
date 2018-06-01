/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        getInvertTree(root);
        return root;
    }
    void getInvertTree(TreeNode* t){
        if(t!=NULL){
            TreeNode* tmp = t->left;
            t->left = t->right;
            t->right = tmp;
        }
        if(t==NULL) return;
        getInvertTree(t->left);
        getInvertTree(t->right);
    }
};