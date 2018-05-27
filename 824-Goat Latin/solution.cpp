class Solution {
public:
    string toGoatLatin(string S) {
        int flag=0,idx,ide;
        int c1=0,c2=0,num=0;
        string ans;
        for(int i=0; i<S.length(); i++){
            if(!flag){
                flag=1;
                idx=i;
                if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u'
                  ||S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U'){
                    c1=1;
                }else{
                    c2=1;
                }
            }
            else if(S[i]==' '){
                num++;
                ide=i;
                string tmp = S.substr(idx, ide-idx);
                if(c1){
                    tmp += "ma";
                }else if(c2){
                    char cc = S.at(idx);
                    tmp.erase(0, 1);
                    tmp += cc;
                    tmp += "ma";
                }
                for(int j=0; j<num; j++){
                    tmp += "a";
                }
                ans += tmp+" ";
                flag=0;
                idx=-1;
                c1=0;
                c2=0;
            }
            //坑点2：这里一开始写成else-if，然后发现不对，当最后一个字符串只有一个字符的时候，这里无法被计算到，所以就改成了if
            if(i==S.length()-1){
                num++;
                ide=i;
                //坑点：忘记这里最后一个是字符，并不是空格，所以长度应为: ide-idx+1，别忘了加1！！！
                string tmp = S.substr(idx, ide-idx+1);
                if(c1){
                    tmp += "ma";
                }else if(c2){
                    char cc = S.at(idx);
                    tmp.erase(0, 1);
                    tmp += cc;
                    tmp += "ma";
                }
                for(int j=0; j<num; j++){
                    tmp += "a";
                }
                ans += tmp;
            }
        }
        return ans;
    }
};