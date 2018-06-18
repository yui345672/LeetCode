class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int len1=list1.size(), len2=list2.size();
        for(int sum=0; sum<len1+len2-1; sum++){
            for(int i=0; i<=sum; i++){
                // 一开始忘加判断条件了,所以 RE 了。
                if(i<len1 && sum-i<len2 && list1[i]==list2[sum-i]){
                    ans.push_back(list1[i]);
                }
            }
            if(!ans.empty()){
                return ans;
            }
        }
    }
};