class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z')
                    mp[ch].push_back({i, j});
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [moves, cell] = pq.top();
            pq.pop();

            auto [row, col] = cell;

            if (moves > dist[row][col])
                continue;

            if (row == n - 1 && col == m - 1)
                return moves;

            char ch = matrix[row][col];

            // Teleport (cost = 0)
            if (ch >= 'A' && ch <= 'Z' && !mp[ch].empty()) {
                for (auto [x, y] : mp[ch]) {
                    if (moves < dist[x][y]) {
                        dist[x][y] = moves;
                        pq.push({moves, {x, y}});
                    }
                }
                mp[ch].clear();
            }

            // Walk (cost = 1)
            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (matrix[nr][nc] == '#')
                    continue;

                if (moves + 1 < dist[nr][nc]) {
                    dist[nr][nc] = moves + 1;
                    pq.push({moves + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};