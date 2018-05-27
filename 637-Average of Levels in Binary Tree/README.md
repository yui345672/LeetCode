## 题意
   给你一个非空的树，然后让你计算每一层上节点的平均值。
   
## 思路
   一开始想着是怎么遍历比较好。要既能够记录层数、又能够记录值的那种。
   
   后来想到了图的形式，一个点连接着一个点那种。
   
   所以，用队列（queue）来保存每一层的节点，并同时记录在该层中有几个节点。然后我们分别将这些节点一个一个弹出，然后保存它们的和，并同时将该节点
   所连接着的左右节点都放进队列去。当遍历完当前所有层的节点后，然后计算该层的平均值，并保存下来。
   
   另一种思路是类似于 DFS （深度优先搜索）：
   
   用递归的方式，并同时开两个数组，一个叫 sum[i] ，用来保存在第 i 层的节点的和； 
   另一个叫 counts[i] ，用来保存第i层有多少个节点。
   
   代码参考如下：
   
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        std::vector<double> sum;
        std::vector<int> counts;

        helper(root, sum, counts, 0);

        std::vector<double> result;

        for (int i = 0; i < sum.size(); ++i) {
            result.push_back(sum[i] / counts[i]);
        }

        return result;

    }

    void helper(TreeNode* root, std::vector<double>& sum, std::vector<int>& counts, int level) {
        // 如果当前节点是空的，那么就返回
        if (root == nullptr) {
            return;
        }

        // 如果当前层，sum 和 counts 还没有保存到那一层，那么就把当前的值放到数组中去
        // 相当于是重新开了一个空间
        if (level == sum.size() && level == counts.size()) {
            sum.push_back(root->val);
            counts.push_back(1);
        } else {
            // 否则的话，直接将现在的值加到数组中的该层就可以了
            sum[level] += root->val;
            counts[level] += 1;
        }

        // 注意这里是level+1
        helper(root->left, sum, counts, level + 1);
        helper(root->right, sum, counts, level + 1);
    }
};

   ```
