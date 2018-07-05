class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> nums;
        for(int i=0; i<letters.size(); i++){
            nums.push_back(letters[i]-'a');
        }
        int left=0, right=nums.size(), mid, numTarget=(target-'a');
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>numTarget){
                right=mid;
            }else if(nums[mid]<=numTarget){
                left=mid+1;
            }
        }
        if(left==nums.size()){
            return letters[0];
        }
        return letters[left];
    }
};