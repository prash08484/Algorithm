
// T.C. : O(n+m)

bool dfsBipartite(vector<int>&color,vector<vector<int>>&adj,int c,int i){
    color[i]=c;
    for(auto &it:adj[i]){
        if(color[it]==0){
            bool chk=dfsBipartite(color,adj,3-c,it);
            if(!chk)return false ; }
        else if(color[it]==c){
            return false;
        }
    }
    return true;
} 

bool Bipartite(int n,auto &adj,vector<int>&color){ 
for(int i=1;i<=n;i++){
    if(color[i]==0){
        bool chk=dfsBipartite(color,adj,1,i);
        if(!chk){
        // IMPOSSIBLE
             return 0;
        }
    }
} 
  return 1;  
  
}
 
 
 
 
