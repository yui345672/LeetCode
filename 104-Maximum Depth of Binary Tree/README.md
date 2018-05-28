## 题意
   给一棵二叉树，让你求出它的最大深度。
   
   最大深度就是：从根节点到叶子节点所经过的途中，所获得到的最多的节点的数量。
   
   叶子节点：没有左右孩子的节点。
   
## 思路
   很简单，递归扫描整棵树就行。
   
   这里有一个判断条件，就是说只有左孩子和右孩子都没有的情况下，我们才对高度进行更新，因为这个说明我们现在遇到的是叶子节点。
   
   如果碰到一个空节点呢？那么我们就直接返回好了，因为如果再访问空节点的左右孩子的话，那么是会报错的。
   
   ```c++
   void getMaxDepth(TreeNode* root, int height){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            mDepth=max(mDepth, height);
            return;
        }
        getMaxDepth(root->left, height+1);
        getMaxDepth(root->right, height+1);
    }
   ```
