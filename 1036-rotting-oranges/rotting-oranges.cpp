class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, minutes = 0;

        // Step 1: Count fresh oranges and push rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        // Step 2: BFS
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1) {
                        grid[nr][nc] = 2; // rot it
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};