class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // pos[original_index] = position in sorted array
        vector<int> pos(n), comp(n);

        int cid = 0;
        pos[arr[0].second] = 0;
        comp[0] = cid;

        for(int i = 1; i < n; i++) {
            pos[arr[i].second] = i;
            if(arr[i].first - arr[i-1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // next[i] = farthest index reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for(int i = 0; i < n; i++) {
            while(r + 1 < n && arr[r + 1].first - arr[i].first <= maxDiff)
                r++;
            nxt[i] = r;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u, v);

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int res = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    res += (1 << k);
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};