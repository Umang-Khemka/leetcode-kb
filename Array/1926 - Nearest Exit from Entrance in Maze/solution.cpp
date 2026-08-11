class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = true;

        int moves = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r, c] = q.front();
                q.pop();

                if ((r == 0 || r == m-1 || c == 0 || c == n-1) &&
                    !(r == entrance[0] && c == entrance[1])) {
                    return moves;
                }

                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       maze[nr][nc] == '.' &&
                       !vis[nr][nc]) {

                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};