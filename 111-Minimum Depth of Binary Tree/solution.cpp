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
    int mDepth=99999999;
    int minDepth(TreeNode* root) {
        getMinDepth(root, 1);
        if(mDepth==99999999) mDepth=0;
        return mDepth;
    }
    void getMinDepth(TreeNode* root, int level){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            mDepth=min(mDepth, level);
            return;
        }
        getMinDepth(root->left, level+1);
        getMinDepth(root->right, level+1);
    }
};