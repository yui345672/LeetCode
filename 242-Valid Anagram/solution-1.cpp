class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1=s.length(), len2=t.length();
        if(len1!=len2) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0; i<len1; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        int flag=0;
        for(int i=0; i<len2; i++){
            if(mp2[t[i]]!=mp1[t[i]]){
                flag=1;
                break;
            }
        }
        if(flag) return false;
        else return true;
    }
};