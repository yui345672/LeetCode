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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        //新建一棵没有节点的数
        TreeNode* nT;
        getNewTree(nT, root, L, R);
        return nT;
    }
    void getNewTree(TreeNode* &nT, TreeNode* oldT, int L, int R){
        if(oldT->val == L){
            nT = new TreeNode(0);
            nT->val = oldT->val;
            nT->left = NULL;
            if(oldT->right) getNewTree(nT->right, oldT->right, L, R);
            return;
        }else if(oldT->val < L){
            if(oldT->right) getNewTree(nT, oldT->right, L, R);
        }else if(oldT->val == R){
            nT = new TreeNode(0);
            nT->val = oldT->val;
            nT->right = NULL;
            if(oldT->left) getNewTree(nT->left, oldT->left, L, R);
            return;
        }else if(oldT->val > R){
            if(oldT->left) getNewTree(nT, oldT->left, L, R);
        }else{
            nT = new TreeNode(0);
            nT->val = oldT->val;
            if(oldT->left) getNewTree(nT->left, oldT->left, L, R);
            if(oldT->right) getNewTree(nT->right, oldT->right, L, R);
        }
    }
};