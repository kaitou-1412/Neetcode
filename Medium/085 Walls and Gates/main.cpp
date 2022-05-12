class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        int INF = 2147483647;
        int nr = rooms.size();
        int nc = rooms[0].size();
        vector<vector<bool>> vis(nr, vector<bool> (nc, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        vector<pair<int, int>> adjacentNodes = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = f.first;
                int c = f.second;
                int rn = r + adjacentNodes[i].first;
                int cn = c + adjacentNodes[i].second;
                if (rn < nr && rn >= 0 && cn < nc && cn >= 0 && !vis[rn][cn] && rooms[rn][cn] == INF) {
                    rooms[rn][cn] = rooms[r][c] + 1;
                    vis[rn][cn] = true;
                    q.push({rn, cn});
                }
            }
        }
        return rooms;
    }
};