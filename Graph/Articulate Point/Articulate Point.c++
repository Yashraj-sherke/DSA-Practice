class Solution {
    int timer = 0;

    void dfs(int u, int parent,
             vector<vector<int>>& adj,
             vector<int>& tin,
             vector<int>& low,
             vector<int>& vis,
             vector<int>& mark) {

        vis[u] = 1;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!vis[v]) {
                dfs(v, u, adj, tin, low, vis, mark);
                low[u] = min(low[u], low[v]);
                children++;

                // Non-root articulation condition
                if (parent != -1 && low[v] >= tin[u]) {
                    mark[u] = 1;
                }
            }
            else {
                // Back edge
                low[u] = min(low[u], tin[v]);
            }
        }

        // Root articulation condition
        if (parent == -1 && children > 1) {
            mark[u] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n, -1), low(n, -1), vis(n, 0), mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, tin, low, vis, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i]) ans.push_back(i);
        }

        return ans;
    }
};
