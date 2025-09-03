
// E : edges , V : vertices
// T.C. O(ElogE) 
// S.C. O(V)
class DSU{
public:
      vector<int> parent;
      vector<int> rank;

    DSU(int n){
        parent.resize(n+1);
        iota(all(parent),0);
        rank.resize(n+1,0);
    }

  int find(int x){
    if (x == parent[x])
        return x;
             
    // Path Compression 
    parent[x] = find(parent[x]); 
    return parent[x];
 }

  bool unionRank(int x,int y){ // union by rank

    int a = find(x);
    int b = find(y);
    if (a == b)
        return 0;

    if (rank[a] > rank[b]) {
        parent[b] = a; }
    else if (rank[a] < rank[b]){
        parent[a] = b; }
    else {
        parent[a] = b;
        rank[b]++; }
    return 1;
  }
};

 // Format of edges[i] = {wt,{u,v}} 
void kruskal(int n, vector<pair<int,pair<int,int>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
  
    int mst_weight = 0;
    vector<pair<int,pair<int,int>> mst; // Format of mst[i] = {wt,{u,v}} 
  
    for (auto& e : edges) {
      int u=e.second.first, v=e.second.second;
        if(dsu.unionRank(u,v)) {
            mst_weight += e.first;
            mst.push_back(e);
        }
    } 
  
    // for (auto& e : mst) {
    //     cout << e.second.first << " " << e.second.second << " " << e.first << endl;
    // }
}

