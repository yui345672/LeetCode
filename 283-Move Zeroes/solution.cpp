class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum=0, idx=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                if(idx==-1) idx=i;
                zeroNum++;
            }else{
                if(idx!=-1){
                    nums[idx]=nums[i];
                    idx++;
                }
            }
        }
        for(int i=0; i<zeroNum; i++){
            nums[idx++]=0;
        }
    }
};