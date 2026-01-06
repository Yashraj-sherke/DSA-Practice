class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<int> adj[V];
        vector<int> indegree(V, 0);

        // Build graph
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]); // b -> a
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push courses with no prerequisites
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
