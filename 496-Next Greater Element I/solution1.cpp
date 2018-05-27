class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<findNums.size(); i++){
            int idx = mp[findNums[i]];
            int flag=0;
            for(int j=idx+1; j<nums.size(); j++){
                if(nums[j]>findNums[i]){
                    flag=1;
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(!flag) ans.push_back(-1);
        }
        return ans;
    }
};