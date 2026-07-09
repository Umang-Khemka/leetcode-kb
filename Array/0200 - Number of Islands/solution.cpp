class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

public:
    void bfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !visited[nr][nc] &&
                    grid[nr][nc] == '1') {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, visited, grid);
                }
            }
        }

        return cnt;
    }
};