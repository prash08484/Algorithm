// O(n ^ 3)
// All pair shortest paths 
// Maintain p[][] for getting path.Recursively find path between i and p[i][j], p[i][j] and j.

void FloydWarshall(int n, vector<vector<pair<ll, ll>>>&adj, vector<vector<ll>> &dist) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int u = 0; u < n; u++) {
        for (auto &it : adj[u]){
            ll v=it.first, w=it.second;
            dist[u][v] = min(dist[u][v], w);
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) // for updating only when there is a path
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
