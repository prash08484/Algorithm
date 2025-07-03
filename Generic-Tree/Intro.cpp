

//In-Out Time : 
    map<int,pii>mpp;
    int t=0;
    void dfsTime(vi adj[],int node,int parent){
        t++;
        mpp[node].first=t;
         range(adj[node]){
            if(it==parent)continue;
            else{ 
                dfsTime(adj,it,node);
            }
         }
         mpp[node].second=t;
    }

 
// Dfs Traversal : 
    void dfs(vi adj[],vi &ans,int node,int parent){
         range(adj[node]){
            if(it==parent)continue;
            else{
                ans.pb(it);
                dfs(adj,ans,it,node);
            }
         }
    }


// Suboridinate : 
const int n=2*1e5+5;
  vi arr(n);
int subordinate(vi adj[],int node,int parent){
    arr[node]=0;
    int cnt=0; 
    range(adj[node]){
        if(it==parent)continue;
        cnt+=dfs(adj,it,node);}
    arr[node]=cnt;
    return cnt+1;
}

 
void solve(){
     // Generic Tree
     int n;
     cin>>n;
     vi adj[n+1];

     flp(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     } 
  
    // dfs traversal
       vi ans;
       dfs(adj,ans,1,-1);
       print_vec(ans);
     
    // In-Out time 
       dfsTime(adj,1,-1);  
}
 
