

void dfs(ll node, ll parent,vll adj[],vvll &dp){
    dp[node][0]=parent;

    flp(i,1,17){
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }

    for(auto &it:adj[node]){
        if(it==parent)continue;
        dfs(it,node,adj,dp);
    }
}


 
 
bool doTestcasesExist=0; 
void solve(){
  
 ll n; 
 cin>>n; 

 vll adj[n+1]; 
 flp(i,0,n-1){
    ll u,v; 
    cin>>u>>v; 
    adj[u].pb(v);
    adj[v].pb(u);
 }

 vvll dp(n+1,vll(17,0));
 dfs(1,0,adj,dp);

 ll q; cin>>q; 
 while(q--){

    // query
    ll node; cin>>node; 
    ll k; cin>>k;  

    flpb(i,16,0){
        if((k>>i)&1){
            node=dp[node][i]; 
        }
    }
    cout<<node<<nline; 
 }

 

 
}
