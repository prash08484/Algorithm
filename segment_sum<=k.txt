
void solve(){
 
 ll n,k;
 cin>>n>>k; 

 vll arr(n); 
 read(arr);

 ll cnt=0;
 ll l=-1,r=-1;
 ll sum=0; 
 
 flp(i,0,n){

  sum+=arr[i];
  r++;
  if(l==-1)l=r;
  
  while(sum>k){ sum-=arr[l]; l++; }
 
  if(sum<=k){
    cnt+=(r-l+1);} }

  cout<<cnt<<nline;  
 
  }
