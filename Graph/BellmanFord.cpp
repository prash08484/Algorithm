
// T.C. : O(V*E)

void BellmanFord(int n, int src, 	vector<pair<ll, pair<int, int>>> &edges, vector<ll>& dist) {
	fill(begin(dist),end(dist), INF); 
  vector<int>parent(n+1,-1); // Trace path. to src
	dist[src] = 0;
  bool change; 
  
	for (int i = 0; i < n-1; i++) {
    change=0;
		for (auto j : e) {
      if(dist[j.S.S]>dist[j.S.F]+j.F){
        parent[j.S.S]=j.S.F;
        change=1; 
      }
			dist[j.S.S] = min(dist[j.S.S], dist[j.S.F] + j.F);
		}
    if(!change)break;
	}
  
	// Checking negative cycle && Get -ve cycle. 
  int CyclingNode=-1;
  for (auto j : e) {
			if (dist[j.S.S] > dist[j.S.F] + j.F) {
				dist[j.S.S] = dist[j.S.F] + j.F;
        CyclingNode=j.S.S;
        parent[j.S.S]=j.S.F; 
			}
		}
  
  // return parent ; // traceback path. 
}
  
