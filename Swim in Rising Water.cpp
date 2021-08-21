class Solution {
public:
    void fillPath(vector<vector<int>> & grid,vector<vector<bool>> &visited, int row,int col,int t){
        if(row<0 || col<0 || row>=grid.size() || col>=grid.size())
            return;
        if(grid[row][col]>t || visited[row][col])
            return;
        visited[row][col]=true;
        fillPath(grid, visited,row-1,col,t);
        fillPath(grid, visited,row+1,col,t);
        fillPath(grid, visited,row,col-1,t);
        fillPath(grid, visited,row,col+1,t);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int left=0;
        int right=n*n-1;
        int mid,best;
        while(left<=right){
            mid = left + (right-left)/2;
            vector<vector<bool>> visited(n,vector<bool>(n));
             fillPath(grid, visited, 0, 0, mid);
            if(visited[n-1][n-1]){
                best=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return best;
    }
};
