// T.C. :  O(n)
  
void prefixSuffix(){
  
  int n,k; cin>>n>>k; 
  vector<int>a(n+1); // input array
  
  for(int i=1;i<=n;i++){
      cin>>a[i];
  }

  vector<int>b(n+1); // Prefix broken size of k e.g. { (A[1]), (A[1]+A[2]), ..., (A[1]+..+A[k]), (A[k+1]), (A[k+1]+A[k+2]), ... }
  vector<int>c(n+1); // Suffix broken size of k  e.g. { (A[1]+...+A[k]), (A[1]+..+A[k-1]), ..., (A[k]), (A[k+1]+...+A[2k]),.. } 
  
// Prefix 
  for(int l=1,r=k; l<=n; l+=k,r+=k){
    r=min(n,r);
   
    long long temp=LINF;
    for(int i=l; i<(r+1); i++){
        temp=min(a[i],temp); 
        b[i]=temp;
    }
  }

// Suffix 
  for(int l=1,r=k; l<=n; l+=k,r+=k){
    r=min(n,r);
    long long temp=LINF;
    for(int i=r; i>=l; i--){
        temp=min(temp,a[i]); 
        c[i]=temp;
    }
  }

  long long ans=0; 
  for(int l=1,r=k; r<=n; l++,r++){  
      ans^=min(b[r],c[l]);
  }


  cout<<ans<<nline;

}
