class Solution {
public:
    
    vector<int> getArray(int number){
        int jj = 10;
        vector<int> res;
        while(number != 0){
            res.push_back(number % 10);
            number = number / 10;
        }
        return res;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> num_list;
        for(int i=left; i<=right; i++){
            vector<int> arr = getArray(i);
            int flag = 0;
            for(int j=arr.size()-1; j>=0; j--){
                if(arr[j] == 0){
                    flag = 1;
                    break;
                }
                if(i % arr[j] != 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) num_list.push_back(i);
        }
        return num_list;
    }
    
};