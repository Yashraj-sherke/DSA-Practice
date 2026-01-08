class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Convert edge list to adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Min heap {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        pq.push({0, src});
        
        while(!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Ignore outdated entries
            if(currDist > dist[node]) continue;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                
                if(dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
