class Solution {
    long long int ans=0;
    int  mod=1e9+7;
    int t[52][52][52];
    
    long long dfs(int m,int n,int sr,int sc,int maxMove){
        
        if(sr<0 || sc<0 || sr>=m ||sc>=n){
            return 1;
        }
        //it is not cross the boundary so, no way
        if(maxMove==0)
            return 0;
    
        //if already computed then return the value
        if(t[sr][sc][maxMove]!=-1){
            return t[sr][sc][maxMove];
        }
        long long way=0;
        
        //counting all the ways in maxMove
        way=(way+dfs(m,n,sr+1,sc,maxMove-1))%mod;
        way=(way+dfs(m,n,sr-1,sc,maxMove-1))%mod;
        way=(way+dfs(m,n,sr,sc+1,maxMove-1))%mod;
        way=(way+dfs(m,n,sr,sc-1,maxMove-1))%mod;
        
        //store the value
        t[sr][sc][maxMove]=way%mod;
        
        return t[sr][sc][maxMove]%mod;
        
    } 
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        ans = dfs(m,n,startRow,startColumn,maxMove);
        return ans%mod;
        
    }
};
