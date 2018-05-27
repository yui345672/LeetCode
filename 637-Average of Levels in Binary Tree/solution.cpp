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
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
		// 要用__int64形式的,要不然数据会溢出.
        std::int64_t num=1;
        while(!q.empty()){
            std::int64_t sum=0;
            std::int64_t tmp=num,tmpNum=num;
            num=0;
            while(tmp){
                TreeNode* t = q.front();
                sum += t->val;
                q.pop();
                if(t->left){
                    q.push(t->left);
                    num++;
                }
                if(t->right){
                    q.push(t->right);
                    num++;
                }
                tmp--;
            }
            double aveNum = sum*1.0 / tmpNum;
            ans.push_back(aveNum);
        }
        return ans;
    }
};