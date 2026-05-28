// O(VlogV + ElogV)
// Single Source Shortest Path

void Dijkstra(int src, vector<ll> &dist, vector<vector<pair<ll, ll>>> &adj) {  
	dist[src] = 0;
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
	q.push({0, src});
	while (!q.empty()) {
		pair<ll, ll> curr = q.top();
		q.pop();
		int u = curr.second;
		ll d_u = curr.first;
		if (d_u != dist[u]){
			continue;
	    }
		for (auto it : adj[u]) {
          int v=it.first, wt=it.second;
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt; 
				q.push({dist[v], v});
			}
		}
	}
}


