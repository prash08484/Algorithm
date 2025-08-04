int n,m; cin>>n>>m;
vector<vector<ll>>a(n,vector<ll>(m));

for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>a[i][j];

/*2D Prefix Sum */
vector<vector<ll>>preSum(n+1,vector<ll>(m+1,0));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        ll curr=a[i][j];
        if(i>0 and j>0){
            curr+=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]; }
        else if(i>0){
            curr+=preSum[i-1][j]; }
        else if(j>0){
            curr+=preSum[i][j-1]; }
        preSum[i][j]=curr;
    }
}
