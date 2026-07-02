//  1-based indexing

//  T.C. : O( nlogn + query*log(n) )
//  O(nlogn) for-building-parent-array-using-binary-lifting + O(log(n))-for-each-query

int LOG; 
void BinaryLifting(vector<vector<int>>&adj, vector<vector<int>>&parent, vector<int>&level, int node, int par, int lvl){  // Binary Lifting
    parent[node][0] = par; 
    level[node] = lvl;
    for(int i = 1;i < LOG; i++){ 
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for(auto &it : adj[node]){
        if(it == par) continue; 
        BinaryLifting(adj, parent, level, it, node, lvl+1);
    }
}
 
void solveLCA(){
  
    int n,query; // no. of node and query 
    cin>>n>>query; 

    vector<vector<int>>adj(n+1); // adj. list 
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;   
        adj[u].pb(v);
        adj[v].pb(u); 
    }

    LOG = __lg(n) + 1; // max. lifting 
    
    vector<int> level(n+1, 0);  // Store the Level of node's 
    vector<vector<int>> parent(n+1, vector<int>(LOG, 0));  // Parent Array of Binary Lifting
   
    // execute helper function BinaryLifting
    // adj-list, parent-array, start-node, parent, level  
    // Root = 1
    BinaryLifting(adj, parent, level, 1, 0, 0); 
    

    // Return Kth Parent of node
    function<int(int, int)> lift = [&](int node, int k)->int{ 
        for(int i = LOG-1 ; i >= 0; i--){
            if((k>>i)&1){
                node = parent[node][i]; 
            }
        }
        return node;
    };


    // LCA of (u,v)
    function<int(int, int)> LCA = [&](int u, int v)->int{ 
        
        int d=level[u] - level[v]; // Level diff. of Node's
    
        // Carry to Same Level 
        if(d < 0) v = lift(v, -d); 
        if(d > 0) u = lift(u, d);

        if(u == v) return u;

        for(int i = LOG-1 ; i >= 0; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i], v = parent[v][i];
            }
        }
        
        return parent[u][0]; 
    };  
    
   //  while(query--){
   //      int u,v; cin>>u>>v;   
   //      int lca=LCA(u,v); 
   //      cout<<lca<<'\n';
   // }    
}
