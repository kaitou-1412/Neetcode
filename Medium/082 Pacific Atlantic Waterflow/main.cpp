class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<int>> &ocean) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if(grid[i][j] < prev) return;    
        if(ocean[i][j] == -1) return;
        ocean[i][j] = -1;
        dfs(grid,i+1,j,grid[i][j],ocean);
        dfs(grid,i,j+1,grid[i][j],ocean);
        dfs(grid,i-1,j,grid[i][j],ocean);
        dfs(grid,i,j-1,grid[i][j],ocean);       
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        /*
            we need only those cells which can visit both atlantic and pacific ocean
            
            like grid[2][2] is ans bcoz 2<3<5 and 1<3<5 it satisfies both condition of pacific               and atlantic too
            
            ex:    grid =  
                            1   2   2   3   5
                            3   2   3   4   4
                            2   4   5   3   1
                            6   7   1   4   5
                            
                    
                calculate two 2d array one storing ans for pacific
                and one storing ans for atlantic
                
                and if we do intersection or check the common in between them than thats the ans
                
        pacific :   we know tht first row and first col will always be the ans
                    for pacific as its always reachable (marking visited cells as -1)
                    
                    (Now in the question its given water will flow from high to low and that's
                     how it works too like in grid[2][2] water will go like 
                     grid[2][2] to grid[2][3] to grid[2][4]
                     and grid[2][2] to grid[1][2] to grid[0][2]
                     
                     since we know that for pacific 1st row and 1st col will always be the ans
                     as it the closest to pacific similarly for atlantic too
                     
                     ex now we can instead of checking water flowing from top to down
                     we can check from down to top as we know that first cell is the ans
                     so the adjcent cells should be greater than that
                     
                     )
               for pacific
               
                    -1  -1  -1  -1  -1
                    -1  -1  -1  -1  -1
                    -1  -1  -1   0   0
                    -1  -1  -1   0   0
                    
               similarly for atlantic too
               
               we run the loop first for top and down covering pacific and atlantic
               bcoz from top we want to go down
               
               and from down we want to go up
         then ,we run the loop first for left and right covering pacific and atlantic
        */
        
        vector<vector<int>> res;
        if(grid.size() == 0) return res;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        for(int j=0; j<m; j++) {
            dfs(grid,0,j,INT_MIN,pacific);
            dfs(grid,n-1,j,INT_MIN,atlantic);
        }
        for(int i=0; i<n; i++) {
            dfs(grid,i,0,INT_MIN,pacific);
            dfs(grid,i,m-1,INT_MIN,atlantic);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] == -1 and pacific[i][j] == atlantic[i][j]) {
                   res.push_back({i,j});
                }
            }
        }
        return res;   
    }
};