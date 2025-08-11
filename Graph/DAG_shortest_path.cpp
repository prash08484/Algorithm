// NOTE: For DAG Graph Only
// T.C: O(V+E)
// Shortest path from src to dest

void topo_sort(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) topo_sort(u, adj, visited, st);
    }
    st.push(v);
}

int DAG_shortest_path(int n, int m, vector<vector<int>> &adj, int src, int dest) { 
    // Topological sort
    vector<bool> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) topo_sort(i, adj, vis, st);

    // Shortest path from src to all nodes
    vector<int> dist(n + 1, INT_MAX);
    vector<int> prev(n + 1, -1);

    dist[src] = 0;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (dist[u] != INT_MAX) {
            for (int v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    prev[v] = u;
                }
            }
        }
    }

    if (dist[dest] == INT_MAX) { 
        cout << "IMPOSSIBLE\n";
        return -1;
    }

    vector<int> path;
    for (int i = dest; i != -1; i = prev[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    cout << "Length of shortest path: " << dist[dest] << '\n';
    cout << "Path: ";
    for (int x : path) cout << x << " ";
    cout << '\n';

    return dist[dest];
}
