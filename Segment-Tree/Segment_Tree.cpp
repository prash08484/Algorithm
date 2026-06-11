
// T.C. 
// build : O(n) 
// Query and Update : log(n) 
class SegmentTree{ 
    // NOTE : here we used 1 based indexing 
    
    // 1-based indexing : for operation on segment tree pass 1 as starting index 
    // 0-based indexing : for operation on segment tree pass 0 as starting index 

    /* NOTE : You can also take left as 2*i+1 and right as 2*i+2 
               in place of index as 1 then you need to pass 0 
               in size substract one  
    */  
    
    // helper function
    int left( int i ){ return i<<1; }
    int right( int i ){ return (i<<1)|1; }
    int treeSize( int n ){ int sz = ceil(log2(n)); return 1<<(sz + 1); }
public:
    
    // DATA REQ.  
    vector<ll> st; //  global segemnent tree  

    ll merge( const ll &a, const ll &b ){
        return min(a, b);
    }

    ll apply( const ll &a, const ll &b ){
        return a + b;
    }

    SegmentTree( vector<ll>&arr ){
        int n = arr.size(); 

        // size req. to store segment tree
        int sz = treeSize(n); 
        st.resize(sz, 0);

        // build segment tree
        build(1, 0, n-1, arr);
    }
    
    void build( int segIdx, int al, int ar, vector<ll> &arr ){

        if(al == ar){
           // UPDATE MAY NEEDED
            st[segIdx] = arr[al];
            return; 
        }
        
        int mid = ( al + ar )/2; 

        build( left(segIdx), al, mid, arr );
        build( right(segIdx), mid+1, ar, arr );

        st[segIdx] = merge( st[left(segIdx)], st[right(segIdx)] );
    }
    
    /* update [uidx, uval] 1, 0, n-1, uidx, uval  */
    void update(int segIdx, int al, int ar, int uidx, ll uval ){
       
        if(al == ar){
           st[segIdx] = apply( st[segIdx], uval );
           return; 
        }
        
        int mid = ( al + ar )/2;

        if( mid >= uidx ) update( left(segIdx), al, mid, uidx , uval );
        else update( right(segIdx), mid+1, ar, uidx , uval );
       
        st[segIdx] = merge( st[left(segIdx)], st[right(segIdx)] );
    }


    /* find query [ql,qr] 1, 0, n-1, qry_l, qry_r  */
    ll query( int segIdx, int al, int ar, int ql, int qr ){
        
        /* out of bound */
        if( ql > ar || qr < al ){
        // UPDATE MAY NEEDED
            return 0;
        }
        
        /* completer overlap */
        if( al >= ql && ar <= qr ){
            return st[segIdx];
        }
        
        /* parital overlap */
        int mid = ( al + ar )/2;

        auto leftAns = query( left(segIdx), al, mid, ql, qr );
        auto rightAns = query( right(segIdx), mid+1, ar, ql, qr );
        
        return merge( leftAns, rightAns );
    } 
};
