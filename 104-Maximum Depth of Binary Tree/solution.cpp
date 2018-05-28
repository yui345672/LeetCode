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
    int mDepth;
    int maxDepth(TreeNode* root) {
        getMaxDepth(root, 1);
        return mDepth;
    }
    void getMaxDepth(TreeNode* root, int height){
        if(root==NULL){
            mDepth=max(mDepth, height-1);
            return;
        }
        getMaxDepth(root->left, height+1);
        getMaxDepth(root->right, height+1);
    }
};