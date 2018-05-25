class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==0) continue;
                int num=0;
                if(i==0){
                    if(i+1!=grid.size()){
                        if(grid[i+1][j]) num++;   
                    }
                    if(j!=0){
                        if(grid[i][j-1]) num++;
                    }
                    if(j!=grid[i].size()-1){
                        if(grid[i][j+1]) num++;
                    }
                }else if(i==grid.size()-1){
                    if(i-1>=0){
                        if(grid[i-1][j]) num++;   
                    }
                    if(j!=0){
                        if(grid[i][j-1]) num++;
                    }
                    if(j!=grid[i].size()-1){
                        if(grid[i][j+1]) num++;
                    }
                }else{
                    if(grid[i-1][j]) num++;
                    if(grid[i+1][j]) num++;
                    if(j!=0){
                        if(grid[i][j-1]) num++;
                    }
                    if(j!=grid[i].size()-1){
                        if(grid[i][j+1]) num++;
                    }
                }
                if(num==0) perimeter += 4;
                else if(num==1) perimeter += 3;
                else if(num==2) perimeter += 2;
                else if(num==3) perimeter += 1;
            }
        }
        return perimeter;
    }
};