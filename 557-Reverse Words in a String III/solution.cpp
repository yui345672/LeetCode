class Solution {
public:
    string reverseWords(string s) {
        int ids=0,ide=-1;
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                ide=i;
                string str = s.substr(ids, ide-ids);
                reverse(str.begin(), str.end());
                ans += str+" ";
                ids=i+1;
            }
            else if(i==s.length()-1){
                string str = s.substr(ids, s.length()-ids);
                reverse(str.begin(), str.end());
                ans += str;
            }
        }
        return ans;
    }
};