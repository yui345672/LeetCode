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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 不加下面那个判断会错误...
        if(t1==NULL && t2==NULL) return NULL;
        TreeNode* t;
        treeCount(t1,t2,t);
        return t;
    }
    
    void treeCount(TreeNode* t1, TreeNode* t2, TreeNode*& t){
        
        if(t1==NULL && t2==NULL) return;
        if(t1 == NULL){
            t = new TreeNode(0);
            t->val = t2->val;
            if(t2->left!=NULL){
                treeCount(NULL, t2->left, t->left);
            }
            if(t2->right!=NULL){
                treeCount(NULL, t2->right, t->right);
            }   
            return;
        }
        else if(t2 == NULL){
            t = new TreeNode(0);
            t->val = t1->val;
            if(t1->left!=NULL){
                treeCount(t1->left, NULL, t->left);
            }
            if(t1->right!=NULL){
                treeCount(t1->right, NULL, t->right);
            }
            return;
        }
        else if(t1!=NULL && t2!=NULL){
            t = new TreeNode(0);
            t->val = t1->val + t2->val;
            treeCount(t1->left, t2->left, t->left);
            treeCount(t1->right,t2->right, t->right);   
        }
    }
    
};