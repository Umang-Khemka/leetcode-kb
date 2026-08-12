class Solution {
public:
    vector<vector<pair<int, double>>> adj;
    vector<bool> vis;

    double dfs(int current, int destination, double product){
        if(current == destination){
            return product;
        }

        vis[current] = true;

        for(auto it : adj[current]){
            int next = it.first;
            double wt = it.second;

            if(!vis[next]){
                double result = dfs(next,destination,product * wt);

                if(result != -1.0){
                    return result;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;

        int id = 0;

        for(auto& eq : equations){
            if(!mp.count(eq[0])){
                mp[eq[0]] = id++;
            }
            if(!mp.count(eq[1])){
                mp[eq[1]] = id++;
            }
        }

        adj.resize(id);

        for(int i=0;i<equations.size();i++){
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];

            double weight = values[i];

            adj[u].push_back({v,weight});
            adj[v].push_back({u,1.0/weight});
        }

        vector<double> ans;

        for(auto& query : queries){
            string start = query[0];
            string end = query[1];

            if(!mp.count(start) || !mp.count(end)){
                ans.push_back(-1.0);
                continue;
            }

            vis.assign(id,false);

            double result  = dfs(mp[start],mp[end],1.0);

            ans.push_back(result);
        }
        return ans;
    }
};