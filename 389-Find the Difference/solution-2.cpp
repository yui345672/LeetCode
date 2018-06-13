class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        // 注意到题目中说 t 是由 s 变化过来，然后再加上一个字符
        // 所以 t 肯定比 s 多一个字符，而且 t 中有的 s 里面肯定也有
        // 所以最后记录下来只出现过奇数次的字符就是我们要找的!
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]++;
        }
        int len=t.length();
        // 重要!!别忘记了!!
        mp[t[len-1]]++;
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            //cout<<"it->first: "<<it->first<<" it->second: "<<it->second<<endl;
            if((it->second)%2==1){
                return (it->first);
            }
        }
    }
};

