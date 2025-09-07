 

 // Euler Tour for flattening of tree 
int idx=0;
void dfs1(vi adj[],vi &flat,map<int,int>&mpp,int node,int parent){
    if(mpp.count(node)==0){
        mpp[node]=idx; }
 flat.pb(node);
 idx++;
 range(adj[node]){
    if(it==parent)continue;
    dfs1(adj,flat,mpp,it,node);
    flat.pb(node);
    idx++;
 }
}

void dfs2(vi adj[],vi &flat,map<int,pair<int,int>>&mpp,int node,int parent){
     mpp[node].F=idx;
     flat.pb(node);
     idx++;
 range(adj[node]){
    if(it==parent)continue;
    dfs2(adj,flat,mpp,it,node);}

   flat.pb(node);
   mpp[node].S=idx;
    idx++;
}
 
void solve(){
     int n;
     cin>>n;
     vi adj[n+1];

     flp(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi flat;


// Euler Tour Type 1 : ---> 

    // USE :  singl3 subtree container (entry-marked exit mark after subtree all subtree covered)
    
    // map<int,int>mpp; // to store the first index of each node
    // dfs1(adj,flat,mpp,1,-1);
     
    // while(q--){  // to find the LCA (A,B)
    // int a,b;
    // cin>>a>>b;
    // // with the help of segment trees you can find the min level 
    // }

// Euler Tour Type 2 :  ---> 

    // USE: seprate subtree container for each (entry-exit marked)
    
    // map<int,pair<int,int>>mpp; // to store the first index of each node
    // dfs2(adj,flat,mpp,1,-1); 
    
 }
 
