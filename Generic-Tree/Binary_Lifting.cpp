 

// Brute Force --->
//  bool kthParent(vi adj[],int node,int parent,int &targetnode,int &k,int &ans){
//       if(targetnode==node){
//           k--;
//           return true; }
//       range(adj[node]){
//           if(it==parent)continue;
//           bool a=kthParent(adj,it,node,targetnode,k,ans);
//           if(a){
//                  if(k==0){
//                   ans=node;}
//                   k--;
//                  return true;
//           }
//       }
//       return false;
//       }

// Better Soln --->
//   void kthParent(vi adj[],int node,int parent,vi &ans){
//           range(adj[node]){
//               if(it==parent){continue;}
//               ans[it]=node;
//               kthParent(adj,it,node,ans);
//           }
//       }


// Optimal Soln ---> with binary lifting 








bool doTestcasesExist=1;
   // doTestcasesExist=0;
void solve(){
     // Generic Tree
     int n;
     cin>>n;
     vi adj[n+1];

     flp(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
 
// find the kth parent of node 
     int targetnode,k;
     cin>>targetnode>>k;


// Brute Force --->  T.C = q*O(n)
     // int ans=-1;
     // bool check=kthParent(adj,1,-1,targetnode,k,ans);
     // if(check){
     //    if(ans!=-1){cout<<ans<<nline;}
     //    else{cout<<"No such parent exist "<<nline;}}
     // else{cout<<"No such node exist "<<nline;}


// Better Soln --->  T.C. = O(n)+q*O(k)
/* we store first parent of each node in an array then recursion on array */
    //     vi ans(n+1,-1);
    //     kthParent(adj,1,-1,ans); 
    //     debug(ans);
    //     int parent=ans[targetnode];
    //     while(k>=1&&parent!=-1){
    //         if(k==1){
    //         cout<<parent<<nline; return;}
    //         parent=ans[parent];
    //         k--; }
    //     cout<<"wrong targetnode and kthParent"<<nline;
      
// Optimal Son ---> Binary Lifting T.C. = O(nLog(n)) 

    
    





      }

 
