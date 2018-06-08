class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int idx=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==val){
                if(idx==-1) idx=i;
                len--;
            }else{
                if(idx!=-1){
                    nums[idx]=nums[i];
                    idx++;
                }
            }
        }
        return len;
    }
};