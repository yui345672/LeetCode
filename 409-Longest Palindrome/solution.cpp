class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int len=0,odd=0;
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            if((it->second)%2==0){
                len += it->second;
            }else{
                odd=1;
                len += it->second-1;
            }
        }
        // 如果是奇数，那么 len 才增加 1
        if(odd) len ++;
        return len;
    }
};