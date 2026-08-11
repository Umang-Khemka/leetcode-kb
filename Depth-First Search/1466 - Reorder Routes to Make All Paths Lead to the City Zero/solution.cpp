class Solution {
public:
    int cnt = 0;

    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj) {
        for (auto [next, direction] : adj[node]) {

            if (next == parent)
                continue;
            
            
            cnt += direction;

            dfs(next, node, adj);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : connections) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }

        dfs(0, -1, adj);

        return cnt;
    }
};