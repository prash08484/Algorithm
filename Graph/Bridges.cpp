// T.C : O(n)
// ans : {u,v} bridge
// disc,low : discovery time and low value 

int timer=0; 
void bridge(auto &adj,auto &vis,auto &ans,auto &disc,auto &low,int node,int parent){
    vis[node]=1;
    disc[node]=low[node]=timer++;

    for(auto &it:adj[node]){
        if(it==parent)continue; 
        if(!vis[it]){
            bridge(adj,vis,ans,disc,low,it,node);
            low[node]=min(low[node],low[it]); 
            if(low[it]>disc[node]){
                ans.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],disc[it]); 
        }
    }
}
