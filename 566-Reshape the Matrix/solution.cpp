class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int len1 = nums.size();
        int len2 = nums[0].size();
        if(r*c > len1*len2 || r*c < len1*len2) return nums;
        vector<vector<int> > ans;
        int rr=0, cc=0;
        for(int i=0; i<r; i++){
            vector<int> tmp;
            tmp.clear();
            for(int j=0; j<c; j++){
                tmp.push_back(nums[rr][cc++]);
                // 如果列数到达了最大值,那么换一行,列同时清零
                if(cc==len2) rr++,cc=0;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};