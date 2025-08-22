// T.C. : O(V+E) 

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (!vis[u]) dfs1(u, adj, vis, st);
    }
    st.push(v);
}

void dfs2(int v, vector<vector<int>>& adjT, vector<bool>& vis, vector<int>& component) {
    vis[v] = 1;
    component.push_back(v);
    for (int u : adjT[v]) {
        if (!vis[u]) dfs2(u, adjT, vis, component);
    }
}

vector<int> kosaraju(int n, vector<vector<int>>& adj) {
    // Topological sort
    vector<bool> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) dfs1(i, adj, vis, st);
  
    // Transpose graph
    vector<vector<int>> adjT(n);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            adjT[v].push_back(u);

    //  DFS on transposed graph
    fill(vis.begin(), vis.end(), 0);
    vector<vector<int>> sccs;
    while (!st.empty()) {
        int v = st.top(); st.pop();
        if (!vis[v]) {
            vector<int> component;
            dfs2(v, adjT, vis, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}
