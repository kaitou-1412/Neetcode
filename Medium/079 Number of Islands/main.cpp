class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
        grid[i][j]='v';  // mark as visited
        if(i+1 < m && grid[i+1][j]=='1') dfs(grid,i+1,j,m,n);
        if(0 <= i-1 && grid[i-1][j]=='1') dfs(grid,i-1,j,m,n);
        if(j+1 < n && grid[i][j+1]=='1') dfs(grid,i,j+1,m,n);
        if(0 <= j-1 && grid[i][j-1]=='1') dfs(grid,i,j-1,m,n);
        else return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
};