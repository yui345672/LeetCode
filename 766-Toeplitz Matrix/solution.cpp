class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int flag=0;
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) return false;
        else return true;
    }
};