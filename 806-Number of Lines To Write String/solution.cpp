class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sum = 0, lines = 1;
        for(int i=0; i<S.length(); i++){
            if(sum + widths[S[i]-'a'] <= 100){
                sum += widths[S[i]-'a'];
            }else{
                sum = widths[S[i]-'a'];
                lines++;
            }
        }
        vector<int> ans;
        ans.push_back(lines);
        ans.push_back(sum);
        return ans;
    }
};