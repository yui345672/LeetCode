class Solution {
public:
    int findComplement(int num) {
        vector<int> arr;
        while(num){
            arr.push_back(num%2);
            num /= 2;
        }
        int ans=0,jj=1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 0){
                ans += jj*1;
                jj = jj*2;
            }
            else if(arr[i] == 1){
                ans += jj*0;
                jj = jj*2;
            }
        }
        return ans;
    }
};