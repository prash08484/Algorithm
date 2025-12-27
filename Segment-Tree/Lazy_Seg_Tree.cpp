class SegmentTree{
public:
    
    vector<ll>segTree; // segment Tree
    vector<ll>lazy;    // lazy Tree
     
    // Helper Function
    int left(int i){ return i<<1; }
    int right(int i){ return (i<<1)|1;}
    int treeSize(int n){ int sz=ceil(log2(n)); return 1<<(sz+1); }
    
    void propagate(int start,int end,int index){ 
        if(start==end){ 
            lazy[index]=0; 
            return; 
        }
        // UPDATE MAY NEEDED
        lazy[left(index)]+=lazy[index];
        lazy[right(index)]+=lazy[index]; 
        lazy[index]=0; 
    }
 
    ll merge(const ll &a,const ll &b){
        return a+b;
    }

    ll apply(const ll &a,const ll &b){
        return a+b;
    }

    SegmentTree(vector<ll> &arr){
        int n=arr.size(); 
        
        // size req. to store segment tree
        int sz=treeSize(n); 

        segTree.resize(sz,0); 
        lazy.resize(sz,0); 
        
        // build segment tree
        build(arr,0,n-1,1);
    }

    // build segment tree : O(n)
    void build(vector<ll> &arr, int start, int end, int index){
        
        if(start==end){  
            // UPDATE MAY NEEDED
            segTree[index]=arr[start]; 
            return; 
        }

        /* parital overlap */
        int mid=start+(end-start)/2; 
        build(arr,start,mid,left(index));
        build(arr,mid+1,end,right(index));
        
        segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
    }
    
    /* UPDATE [l,r]  */
    void update(int start,int end,int index,int l,int r,ll value){
       
        if(lazy[index]!=0){
            segTree[index]=apply(segTree[index],lazy[index]); 
            propagate(start,end,index); 
        }
    
        /* out of range */ 
        if(l>end or r<start)return;
    
        /* completer overlap */
        if(start>=l and end<=r){
            segTree[index]=apply(segTree[index],value); 
            lazy[index]+=value; 
            propagate(start,end,index); 
            return;
        }
    
        /* parital overlap */
        int mid=start+(end-start)/2; 
        update(start,mid,left(index),l,r,value);
        update(mid+1,end,right(index),l,r,value);
       
       segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
    }

    /* QUERY [l,r]  */
    ll query(int start,int end,int index,int l,int r){
    
        if(lazy[index]!=0){
            segTree[index]=apply(segTree[index],lazy[index]); 
            propagate(start,end,index); 
        }
    
        /* out of range */
        if(l>end or r<start){ 
            // UPDATE MAY NEEDED
            return 0; 
        }
        
        /* completer overlap */
        if(start>=l and r>=end){
            return segTree[index]; 
        }
        
        /* parital overlap */
        int mid=start+(end-start)/2; 
        
        // UPDATE DATATYPE
        ll b=query(start,mid,left(index),l,r); 
        ll a=query(mid+1,end,right(index),l,r);
        return merge(a,b);  
    } 
};
