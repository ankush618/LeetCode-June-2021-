class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //int ans=0;
        int maxarea=0;
        for(int i=0;i<n;i++){
           // ans=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c=0;
                    dfs(i,j,m,n,grid);
                    maxarea=max(maxarea,c);
                }
            }
        }
        return maxarea;
    }
    int c;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid ){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return ;
        
        grid[i][j]=0;
        c++;
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid); 
        dfs(i,j-1,n,m,grid);
    }
};
