class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        stack<int> sk;
        for(int i=0; i<nums.size(); i++){
            while(sk.size() && sk.top()<nums[i]){
                mp[sk.top()]=nums[i];
                sk.pop();
            }
            sk.push(nums[i]);
        }
        // mp count代表的是查看在map中这个key的数量，有的话就是1，没有就是0
        for(int i=0; i<findNums.size(); i++){
            ans.push_back(mp.count(findNums[i]) ? mp[findNums[i]] : -1);
        }
        return ans;
    }
};