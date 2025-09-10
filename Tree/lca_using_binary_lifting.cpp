//  T.C. : O( nlogn + query*log(n) )
//  O(nlogn) for make parent array using binary lifting
//  O(log(n)) for each query

void BinaryLifting(auto &adj,auto &a,int node,int parent){  // Binary Lifting
    a[node][0]=parent; 
    for(int i=1;i<=16;i++){
        a[node][i]=a[a[node][i-1]][i-1];
    }
    for(auto &it:adj[node]){
        if(it==parent)continue; 
        BinaryLifting(adj,a,it,node);
    }
 }
 
void LCA(){
  
   int n,query; // no. of node and query 
   cin>>n>>query; 

   vector<vector<int>>adj(n+1); // adj. list 
   for(int i=1;i<n;i++){
    int u,v; cin>>u>>v;   
    adj[u].pb(v);
    adj[v].pb(u); 
   }

    vector<vector<int>>a(n+1,vector<int>(17,0));  // Parent Array of Binary Lifting

    BinaryLifting(adj,a,1,0); 

    auto lift=[&](int node,int k)->int{ // Return Kth Parent of node
       for(int i=16;i>=0;i--){
            if((k>>i)&1)
            node=a[node][i]; }
        return node;
    };

    auto lca=[&](int u,int v)->int{ // LCA of (u,v)
        int par=-1; 
        for(int i=16;i>=0;i--){
            if(a[u][i]!=a[v][i]){
                u=a[u][i],v=a[v][i];
            }
        }
        if(u==v)return u;
        return a[u][0]; 
    };  


    vector<int>level(n+1,0);  // Store the Level of node's 

    auto Level=[&](){ // Make level of Node
        
        queue<int>q; 
        q.push(1);
        int lvl=1;

        while(!q.empty()){
            int sz=q.size(); 
            for(int i=0;i<sz;i++){
                int node=q.front(); q.pop(); 
                level[node]=lvl;
                for(auto &it:adj[node]){
                    if(it==a[node][0])continue; 
                    q.push(it);
                }
            }
            lvl++;
        }
    };

    Level();

   while(query--){
    int u,v; cin>>u>>v;  

    int d=level[u]-level[v]; // Level diff. of Node's
    
    // Carry to Same Level 
    if(d<0) v=lift(v,-d); 
    if(d>0) u=lift(u,d);
 
    int par=lca(u,v); 
    cout<<par<<'\n';
   }    
}

