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
            if(xx<0||yy<0||xx>=l1||yy>=l2) continue;
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