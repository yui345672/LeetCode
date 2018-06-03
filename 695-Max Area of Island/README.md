## 题意
   给一个二维数组由 0 和 1 组成，然后 1 代表的是小岛。
   
   然后让你找出在这个二维数组中小岛所构成的最大面积（也就是连通在一起的小岛的数量）。
   
## 思路
   很像是之前做过的 dfs 的题目，所以直接上 dfs 了，但是因为很久没写，所以有些细节处理了比较久。
   
```c++
class Solution {
public:
    int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
    int vis[51][51];
    int maxArea=0,num=0;
    int l1,l2;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        l1=grid.size(), l2=grid[0].size();
        memset(vis,0,sizeof(vis));
        for(int i=0; i<l1; i++){
            for(int j=0; j<l2; j++){
                if(grid[i][j]==0) continue;
                else if(vis[i][j]==1) continue;
                else{
                    vis[i][j]=1;
                    //cout<<"i= "<<i<<", j= "<<j<<endl;
                    num=1;
                    dfs(i,j,grid);
                }
            }
        }
        return maxArea;
    }
    void dfs(int x, int y, vector<vector<int>>& g){
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            // 边界条件处理
            if(xx<0||yy<0||xx>=l1||yy>=l2) continue;
            // 访问过了就不再访问了
            if(vis[xx][yy]) continue;
            if(g[xx][yy]==1){
                num++;
                //cout<<"xx-> "<<xx<<" yy-> "<<yy<<"num-> "<<num<<endl;
                vis[xx][yy]=1;
                dfs(xx, yy, g);
            }
        }
        maxArea=max(maxArea, num);
    }
};
```
