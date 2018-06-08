class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        vector<int> ans;
        while(i<j){
            if(numbers[i]+numbers[j]<target) i++;
            else if(numbers[i]+numbers[j]>target) j--;
            else if(numbers[i]+numbers[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                // 因为只有唯一解,所以找到后直接break就可以了
                break;
            }
        }
        return ans;
    }
};