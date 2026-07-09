class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Push all boundary land cells
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                vis[i][0] = true;
                q.push({i, 0});
            }

            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) {
                vis[i][n - 1] = true;
                q.push({i, n - 1});
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                vis[0][j] = true;
                q.push({0, j});
            }

            if (grid[m - 1][j] == 1 && !vis[m - 1][j]) {
                vis[m - 1][j] = true;
                q.push({m - 1, j});
            }
        }

        // BFS
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (grid[nr][nc] == 0 || vis[nr][nc])
                    continue;

                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        // Count enclaves
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};