
vll segTree,lazy;  // segment Tree,lazy Tree
 
// helper function
int left(int i){ return i<<1; }
int right(int i){ return (i<<1)|1;}
int treeSize(int n){ int sz=ceil(log2(n)); return 1<<(sz+1); }
void propagate(int start,int end,int index){
     if(start==end){ lazy[index]=0; return; }
     // UPDATE MAY NEEDED
     lazy[left(index)]+=lazy[index];
     lazy[right(index)]+=lazy[index];
     lazy[index]=0; 
}
// UPDATE RETURN TYPE AND DATA TYPE IN PARAMETER
ll merge(const ll &a,const ll &b){
    return min(a,b);
}

// build segment tree 
void build(auto &arr, int start ,int end ,int index){
    if(start==end){ segTree[index]=arr[start]; return; }
    int mid=start+(end-start)/2; 
    build(arr,start,mid,left(index));
    build(arr,mid+1,end,right(index));
    segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
}

// update [l,r] with value
void update(int start,int end,int index,int l,int r,ll value){
    
    if(lazy[index]!=0){
        segTree[index]+=lazy[index]; 
        propagate(start,end,index); }

    //disjoint 
    if(l>end or r<start)return;

    // complete overlap
    if(start>=l and end<=r){
        segTree[index]+=value; 
        lazy[index]+=value;
        propagate(start,end,index); return;}

    // partial overlap
   int mid=start+(end-start)/2; 
    update(start,mid,left(index),l,r,value);
    update(mid+1,end,right(index),l,r,value);
   
   segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
}

 // return [l,r]
// UPDATE RETURN TYPE 
ll query(int start,int end,int index,int l,int r){

     if(lazy[index]!=0){
        segTree[index]+=lazy[index]; 
        propagate(start,end,index); }

// disjoint : UPDATE RETURN VALUE
if(l>end or r<start){ return LINF; }

// complete overlap  
if(start>=l and r>=end){
 return segTree[index]; }

// partial overlap 
int mid=start+(end-start)/2; 

// UPDATE DATATYPE
ll b=query(start,mid,left(index),l,r); 
ll a=query(mid+1,end,right(index),l,r);
return merge(a,b);  

} 

void solve(){

int n; // size of given array
cin>>n;  

// size req. to store segment tree
int sz=treeSize(n); 

segTree.resize(sz,0); 
lazy.resize(sz,0); 
 
vll arr(n);
read(arr);

// build segment tree
build(arr,0,n-1,1);
 
} 
