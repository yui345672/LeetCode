class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return getMajorityElement(nums, 0, nums.size()-1);
    }
    // 递归获取每部分的出现次数的数字
    int getMajorityElement(vector<int>& nums, int l, int r){
        if(l==r){
            return nums[l];
        }
        
        int mid=(l+r)/2;
        int left=getMajorityElement(nums, l, mid);
        int right=getMajorityElement(nums, mid+1, r);
        
        if(left==right){
            return left;
        }
        
        return judge(nums, left, right);
    }
    // 判断一下是 left 出现次数多还是 right 出现次数多
    int judge(vector<int>& nums, int left, int right){
        int lcount=0, rcount=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==left) lcount++;
            else if(nums[i]==right) rcount++;
        }
        return (lcount > rcount ? left : right);
    }
};