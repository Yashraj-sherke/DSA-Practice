class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> graph(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Step 2: Prim's Algorithm
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int cost = 0;

        pq.push({0, 0});   // {weight, node}
        dist[0] = 0;

        while (!pq.empty()) {

            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            cost += w;

            for (auto &neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v] && weight < dist[v]) {
                    dist[v] = weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return cost;
    }
};
