
// T.C : O(n)
// ans : articulation points
// disc,low : discovery time and low value 

vector<int> articulationPoints(int n, vector<vector<int>>& eg) { 

    vector<vector<int>>adj(n);  
     
    for(auto &it:eg){
        int u=it[0],v=it[1];  
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    } 

    vector<bool>vis(n,0); 
    vector<bool>ans(n,0);
    vector<int>tin(n); // time to enter node
    vector<int>low(n); // lowest possible time to reach any node in descendent
    int timer=0;         
    
    function<void(int,int)>dfs=[&](int i,int p)->void{
        timer++; 
        tin[i]=low[i]=timer;
        vis[i]=1;
        int child=0;
        
        for(auto &it:adj[i]){
            if(it==p)continue; 
            if(vis[it]){
                low[i]=min(low[i],tin[it]); // Back-edge !! NOTE : NOT take low[it] 
            }
            else{
                dfs(it,i); 
                child++;
                
                low[i]=min(low[i],low[it]); 
                
                if(low[it]>=tin[i] and p!=-1){ // if no descendent node have better reachibility than parent
                    ans[i]=1;
                }
            }
        } 
        
    if(child>1 and p==-1){ // for root node child>1 then it's AP
        ans[i]=1;
    }
            
    };
        
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i,-1); 
    }
      
        
    vector<int>res; 
    for(int i=0;i<n;i++){
        if(ans[i])res.emplace_back(i);
    }
         
    return res; 
}
