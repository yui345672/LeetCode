class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp;
        vector<string> ans;
        for(int i=0; i<list1.size(); i++){
            mp[list1[i]]=i;
        }
        int lmin=99999999;
        for(int i=0; i<list2.size(); i++){
            if(mp.count(list2[i])>0){
                int res=mp[list2[i]]+i;
                // 如果当前的比最小值还要小,那么就把之前的清空了进行更新
                if(res<lmin){
                    ans.clear();
                    ans.push_back(list2[i]);
                    lmin=res;
                }else if(lmin==res){
                    // 否则的话,就把当前的字符串也放进数组中去
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};