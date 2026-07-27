class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
                    mp[matrix[i][j]].push_back({i, j});
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        dq.push_front({0, 0});
        dist[0][0] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            int d = dist[r][c];

            if (r == n - 1 && c == m - 1)
                return d;

            char ch = matrix[r][c];

            if (ch >= 'A' && ch <= 'Z' && !mp[ch].empty()) {
                for (auto [x, y] : mp[ch]) {
                    if (d < dist[x][y]) {
                        dist[x][y] = d;
                        dq.push_front({x, y});
                    }
                }
                mp[ch].clear();
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (matrix[nr][nc] == '#')
                    continue;

                if (d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    dq.push_back({nr, nc});
                }
            }
        }

        return -1;
    }
};