class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth < 1) return false;

        q.push({{0, 0}, startHealth});
        best[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [cell, currHealth] = q.front();
            q.pop();

            int r = cell.first;
            int c = cell.second;

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = currHealth - grid[nr][nc];

                if (newHealth >= 1 && newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    q.push({{nr, nc}, newHealth});
                }
            }
        }

        return false;
    }
};