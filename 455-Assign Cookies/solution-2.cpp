class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 注意边界，如果数组为空的话是不能 sort 的
        if(!g.empty()) sort(g.begin(), g.end());
        if(!s.empty()) sort(s.begin(), s.end());
        int pointerG=0, ans=0;
        // 有点像 two-pointers，但其实这里是单指针
        // 这里遍历 s 会比遍历 g 好
        for(int i=0; i<s.size(); i++){
            if(pointerG==g.size()) break;
            if(g[pointerG]<=s[i]){
                ans++;
                pointerG++;
            }
        }
        return ans;
    }
};