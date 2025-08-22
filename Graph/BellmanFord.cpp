
// T.C. : O(V*E)

void BellmanFord(int n, int src,vector<pair<ll, pair<int,int>>> &edges, vector<ll>& dist) {
    
    fill(begin(dist),end(dist), LINF); 
    vector<int>parent(n+1,-1); 
    dist[src] = 0;
    bool change; // Optimization.
  
    for (int i = 0; i <n-1; i++) {
         change=0;
         for (auto &it : edges){
             int u = it.S.F, v=it.S.S;  ll w = it.F;

           // if(dist[u]==LINF)continue; // use if not to consider self loops
           if(dist[v]>dist[u]+w){
              parent[v]=u;
              change=1; 
              dist[v] =  dist[u] + w;
           }
       }
       if(!change)break;
    }
  
    // Checking negative cycle && Get -ve cycle. 
    
     int CyclingNode=-1;
      for (auto &it : edges){
            int u = it.S.F, v=it.S.S; ll w = it.F;

          // if(dist[u]==LINF)continue; // use if not to consider self loops
           if(dist[v]>dist[u]+w){
              parent[v]=u; 
              CyclingNode=v;
              dist[v] = dist[u] + w;
               break;
           }
       }

    if(CyclingNode==-1){ 
        // No cycle
    } 

    /*NOTE :
     To get -ve cycle First Ensure CyclingNode is Inside Cycle */
     for(int i=0;i<n;i++) CyclingNode=parent[CyclingNode]; 
    
    vector<int>cycle; 
    int u=CyclingNode;
    cycle.push_back(u);
    do{
        cycle.push_back(u);
        u=parent[u];
      }while(u!=CyclingNode);  

      reverse(begin(cycle),end(cycle));
         // return cycle;
 
}
