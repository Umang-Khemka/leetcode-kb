class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis,
             int &vertices, int &degreeSum) {

        vis[node] = true;
        vertices++;

        degreeSum += adj[node].size();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, vertices, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                int vertices = 0;
                int degreeSum = 0;

                dfs(i, adj, vis, vertices, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == (vertices * (vertices - 1)) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};