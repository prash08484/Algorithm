vi segTree; //  global segemnent tree 
vi lazy; // lazy segment Tree


int left(int i){
    return 2*i; }
int right(int i){
    return 2*i+1;}

/* NOTE : You can also take left as 2*i+1 and right as 2*i+2 
           in place of index as 1 then you need to pass 0 */    

// making segment tree : O(n)
void build(vi &arr, int start ,int end ,int index){
    if(start==end){
    segTree[index]=arr[start];
    return; }
int mid=(start+end)/2; 
build(arr,start,mid,left(index));
build(arr,mid+1,end,right(index));
segTree[index]=segTree[left(index)]+segTree[right(index)];
}

void propagate(int start,int end,int index){
      if(start==end)return; 
      lazy[2*index]+=lazy[index];
      lazy[2*index+1]=lazy[index];
      lazy[index]=0;
}

// l,r is range to updated with value , index of segTree and start,end is range of segTree
void update(vi &arr,int start,int end,int l,int r,int index,int value){

    if(lazy[index]!=0){ // current have pending changes 
      segTree[index]+=value;
      propagate(start,end,index); } 
  
  if(r<start or l>end){ return; } // out of range 
  
  if(l>=start and r<=end){ // complete overlap 
         segTree[index]+=value;
         lazy[index]+=value;  
         propagate(start,end,index);
    return;
  } 
  
// partial overlap 
  int mid=(start+end)/2; 
    update(arr,start,mid,l,r,left(index),value); 
    update(arr,mid+1,end,l,r,right(index),value);
   
   segTree[index]=segTree[2*index]+segTree[2*index+1];
}


// to find sum from l to r 
int query(int start,int end,int index,int l,int r){
  
     if(lazy[index]!=0){ // current have pending changes 
      segTree[index]+=value;
      propagate(start,end,index); } 

if(l>end || r<start) /* curr sum is out of range */
    return 0;

 /* curr sum is part of query e.g. ask for 1 to 4 
 : curr sum is 1 to 2 then it need so that here */ 
if(start>=l&&end<=r)
    return segTree[index];

int mid=(start+end)/2;
int leftAns=query(start,mid,left(index),l,r);
int rightAns=query(mid+1,end,right(index),l,r);
return rightAns+leftAns;

} 

void Segment_Tree(){

int n; // size of given arr
cin>>n;

// size req. to store segment tree
int sz=ceil(log2(n));
sz=2*pow(2,sz)-1;
segTree.resize(sz,-1);
lazy.resizse(sz,0);

// taking array input 
vi arr(n);
read_vec(arr);

// making segment tree
build(arr,0,n-1,1);


/* e.g. 

 debug(segTree);
 update(arr,0,n-1,1,2,-4);
 debug(query(0,n-1,1,3,3)); 

*/


}
