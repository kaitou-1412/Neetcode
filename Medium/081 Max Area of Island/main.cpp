class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n, int &curr) {
        curr++;
        grid[i][j]=2;  // mark as visited
        if(i+1 < m && grid[i+1][j]==1) dfs(grid,i+1,j,m,n,curr);
        if(0 <= i-1 && grid[i-1][j]==1) dfs(grid,i-1,j,m,n,curr);
        if(j+1 < n && grid[i][j+1]==1) dfs(grid,i,j+1,m,n,curr);
        if(0 <= j-1 && grid[i][j-1]==1) dfs(grid,i,j-1,m,n,curr);
        else return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, curr = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                curr = 0;
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, curr);
                    res = max(res, curr);
                }
            }
        }
        return res;    
    }
};