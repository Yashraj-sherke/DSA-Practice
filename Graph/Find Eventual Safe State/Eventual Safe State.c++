class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adjRev[n];
        vector<int> indegree(n, 0);

        // Build reverse graph
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i); // reverse edge
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNode;

        // Nodes with outdegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn’s algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNode.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
