
// T.C. Construction -> nlog(n) , query -> log(k):where kth parent  

void dfs(int node, int parent, vvi &adj, vvi &dp){
    dp[node][0]=parent;
    for(int i=1;i<17;i++){
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }
    for(auto &it:adj[node]){
        if(it==parent)continue;
        dfs(it,node,adj,dp);
    }
} 

void solve(){
 int n;  cin>>n; 
 vvi adj(n);

 flp(i,0,n-1){
     int u,v; cin>>u>>v; 
     u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
 }

 vvi dp(n,vi(17,0));
 dfs(0,0,adj,dp);

 // query
 int q; cin>>q; 
 while(q--){     
    ll node; cin>>node; 
    ll k; cin>>k; // kth_parent of node
      node--; 
    flpb(i,16,0){
        if((k>>i)&1){
            node=dp[node][i]; 
        }
    }
    cout<<node<<'\n'; 
 }
}
