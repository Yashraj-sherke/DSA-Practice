class Solution {
public:
    bool isPossible(int V, int P, vector<pair<int, int>>& prerequisites) {

        vector<int> adj[V];
        vector<int> indegree(V, 0);

        // Build graph
        for (auto &p : prerequisites) {
            adj[p.first].push_back(p.second);
            indegree[p.second]++;
        }

        queue<int> q;

        // Push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return count == V;
    }
};
