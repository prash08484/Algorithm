
// T.C : O(n)
// ans : articulation points
// disc,low : discovery time and low value 

int timer=0; 
void articulation(auto &adj,auto &vis,auto &ans,auto &disc,auto &low,int node,int parent){
    vis[node]=1;
    disc[node]=low[node]=timer++;
    int child=0; 
    for(auto &it:adj[node]){
        if(it==parent)continue; 
        if(!vis[it]){
            articulation(adj,vis,ans,disc,low,it,node);
            low[node]=min(low[node],low[it]); 
            if(low[it]>=disc[node] and parent!=-1){
                ans.push_back(node);
            }
            child++;
        }
        else{
            low[node]=min(low[node],disc[it]); 
        }
    }
    if(child>1 and parent==-1){
        ans.push_back(node);
    }
}
