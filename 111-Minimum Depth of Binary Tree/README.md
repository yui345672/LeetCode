## 题意
   这道题和 104 有相似之处。
   
   给一棵二叉树，让你找到它的最小的深度。
   
   最小的深度就是在从根节点到最近的叶子节点的最短的路径上所能够收获的节点的数量。
   
## 思路
   和 104 差不多。 有几个坑点我写在代码里了。
   
   ```c++
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
        // 这是一个坑点，如果它什么都没有输入，你得返回高度是0.
        if(mDepth==99999999) mDepth=0;
        return mDepth;
    }
    void getMinDepth(TreeNode* root, int level){
        if(root==NULL) return;
        // 判断叶子节点的方式
        if(root->left==NULL && root->right==NULL){
            mDepth=min(mDepth, level);
            return;
        }
        getMinDepth(root->left, level+1);
        getMinDepth(root->right, level+1);
    }
};
   ```
