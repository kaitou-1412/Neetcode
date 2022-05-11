class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        vector<vector<bool>> vis(nr, vector<bool> (nc, false));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        vector<pair<int, int>> adjacentNodes = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = f.second.first;
                int c = f.second.second;
                int t = f.first;
                ans = t;
                int rn = r + adjacentNodes[i].first;
                int cn = c + adjacentNodes[i].second;
                int tn = t + 1;
                if (rn < nr && rn >= 0 && cn < nc && cn >= 0 && !vis[rn][cn] && grid[rn][cn] == 1) {
                    grid[rn][cn] = 2;
                    vis[rn][cn] = true;
                    q.push({tn, {rn, cn}});
                }
            }
        }
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};