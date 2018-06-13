class Solution {
public:
    bool isAnagram(string s, string t) {
        int mp1[33]={0},mp2[33]={0};
        int len1=s.length(), len2=t.length();
        if(len1!=len2) return false;
        for(int i=0; i<len1; i++){
            mp1[s[i]-'a']++;
            mp2[t[i]-'a']++;
        }
        int flag=0;
        for(int i=0; i<len2; i++){
            if(mp2[t[i]-'a']!=mp1[t[i]-'a']){
                flag=1;
                break;
            }
        }
        if(flag) return false;
        else return true;
    }
};