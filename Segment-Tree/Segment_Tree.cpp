
class SegmentTree{
  private:
    // NOTE : here we used 1 based indexing 
    
    // 1-based indexing : for operation on segment tree pass 1 as starting index 
    // 0-based indexing : for operation on segment tree pass 0 as starting index 
    
    // helper function
    int left(int i){ return i<<1; }
    int right(int i){ return (i<<1)|1;}
    int treeSize(int n){ int sz=ceil(log2(n)); return 1<<(sz+1); }
    ll merge(const ll &a,const ll &b){
        return min(a,b);
    }

    ll apply(const ll &a,const ll &b){
        return a+b;
    }
    
    /* NOTE : You can also take left as 2*i+1 and right as 2*i+2 
               in place of index as 1 then you need to pass 0 
               in size substract one  
    */  


        // making segment tree : O(n)
    void build(vector<ll> &arr, int start ,int end ,int index){
        if(start==end){
           // UPDATE MAY NEEDED
            segTree[index]=arr[start];
            return; 
        }
        int mid=(start+end)/2; 
        build(arr,start,mid,left(index));
        build(arr,mid+1,end,right(index));
        segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
    }


  public: 
    vector<ll> segTree; //  global segemnent tree   

    SegmentTree(vector<ll>&arr){
        int n=arr.size(); 

        // size req. to store segment tree
        int sz=treeSize(n); 
        segTree.resize(sz,0);

        // making segment tree
        build(arr,0,n-1,1);
    }

    void update(int start,int end,int index,int pos,int value){
       
        if(start==end){
           segTree[index]=apply(segTree[index],value);
           return; }
        int mid=(start+end)/2;
        if(mid>=pos)
          update(start,mid,left(index),pos,value);
        else
         update(mid+1,end,right(index),pos,value);
       
        segTree[index]=merge(segTree[left(index)],segTree[right(index)]);
    }


    /* find query [l,r]  */
    ll query(int start,int end,int index,int l,int r){
        
        /* out of range */
        if(l>end || r<start) {
        // UPDATE MAY NEEDED
            return 0;
        }
        
        /* completer overlap */
        if(start>=l&&end<=r){
            return segTree[index];
        }
        
        /* parital overlap */
        int mid=(start+end)/2;
        ll leftAns=query(start,mid,left(index),l,r);
        ll rightAns=query(mid+1,end,right(index),l,r);
        
        return merge(leftAns,rightAns);
    } 
};
