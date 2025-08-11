// T.C. : O(V+E) 

void topo_dfs(int v, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (!vis[u]) topo_dfs(u, adj, vis, st); 
    }
    st.push(v);
}

  // Topological sort
vector<int> topo_sort(int n, vector<vector<int>>& adj) {
  
    vector<bool> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) topo_dfs(i, adj, vis, st);
  
    vector<int>topo_order;
    while(!st.empty()){
      topo.push_back(st.top());
      st.pop();  }

    return topo_order;
}
