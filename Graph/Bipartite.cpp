// T.C. : O(n+m)

void dfsBipartite(vector<int>&color, vector<vector<int>>&adj, int c, int i, bool &ok){
    color[i]=c;
    for(auto &it : adj[i]){
        if(color[it] == -1){
            dfsBipartite(color, adj, 3^c, it, ok); 
        } 
        else if(color[it] == c){
            ok=0;
        }
    } 
} 

bool Bipartite(int n, vector<int>&color, vector<vector<int>> &adj){ 

    fill(begin(color),end(color),-1);
    
    bool ok = 1; 
    for(int i=0;i<n;i++){
        if(color[i] != -1)continue; 
        dfsBipartite(color, adj, 0, i, ok);
    } 
    return ok;  
}
 
 
