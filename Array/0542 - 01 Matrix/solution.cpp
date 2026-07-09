class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   ans[nr][nc] == -1) {

                    ans[nr][nc] = ans[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};