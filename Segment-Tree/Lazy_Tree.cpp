
// T.C. : 
 // build : O(n)
 // Query and Update : O(logn) 
class SegmentTree{
     
    // Helper Function
    int left( int i ){ return i<<1; }
    int right( int i ){ return (i<<1)|1; }
    int treeSize( int n ){ int sz=ceil(log2(n)); return 1<<(sz+1); }

 public:
    
    // DATA REQ. 
    vector<ll>st;       // segment Tree
    vector<ll>lazy;    // lazy Tree
    
 
    ll merge( const ll &a, const ll &b ){
        return a + b;
    }

    ll apply( const ll &a, const ll &b ){
        return a + b;
    }

    void propagate( int segIdx, int al, int ar ){ 

        if(al == ar){ 
            lazy[segIdx] = 0; 
            return; 
        }

        // UPDATE MAY NEEDED
        lazy[left(segIdx)] += lazy[segIdx];
        lazy[right(segIdx)] += lazy[segIdx]; 
        lazy[segIdx] = 0; 
    }

    SegmentTree( vector<ll> &arr ){
        int n=arr.size(); 
        
        // size req. to store segment tree
        int sz=treeSize(n); 

        st.resize(sz,0); 
        lazy.resize(sz,0); 
        
        // build segment tree
        build(1, 0, n-1, arr);
    }

    // build segment tree : O(n)
    void build( int segIdx, int al, int ar, vector<ll> &arr ){
        
        if(al == ar){  
            // UPDATE MAY NEEDED
            st[segIdx] = arr[al]; 
            return; 
        }

        /* parital overlap */
        int mid = ( al + ar ) / 2; 

        build( left(segIdx), al, mid, arr );
        build( right(segIdx), mid+1, ar, arr );
        
        st[segIdx] = merge( st[left(segIdx)], st[right(segIdx)] );
    }


    /* QUERY [ql,qr] : segment_idx, arr_start_idx, arr_end_idx, qry_left_idx, qry_right_idx   */
    /* QUERY [ql,qr] : 1, 0, n-1, ql qr   */  

    ll query( int segIdx, int al, int ar, int ql, int qr ){
    
        if(lazy[segIdx] != 0){

            st[segIdx] = apply( st[segIdx], lazy[segIdx] ); 
            propagate( segIdx, al, ar ); 

        }
    
        /* out of range */
        if( ql > ar  || qr < al ){ 
            // UPDATE MAY NEEDED

            return 0; 
        }
        
        /* completer overlap */
        if( al >= ql && qr >= ar ){
            return st[segIdx]; 
        }
        
        /* parital overlap */
        int mid =  ( al + ar ) / 2; 
        
        // UPDATE DATATYPE
        ll ansL = query( left(segIdx), al , mid, ql, qr ); 
        ll ansR = query( right(segIdx), mid+1 , ar, ql, qr);

        return merge( ansL,ansR );  
    } 

   
    /* UPDATE [ul,ur] : segment_idx, arr_start_idx, arr_end_idx, update_left_idx, update_right_idx, update_value   */
    /* UPDATE [ul,ur] : 1, 0, n-1, ul, ur, uval   */  

    void update( int segIdx, int al, int ar, int ul, int ur, ll uval ){
       
        if( lazy[segIdx] !=0 ){

            st[segIdx] = apply( st[segIdx], lazy[segIdx] ); 
            propagate( segIdx, al, ar );  

        }
    
        /* out of range */ 
        if( ul > ar  || ur < al )return;
    
        /* completer overlap */
        if( al >= ul && ar <= ur){

            st[segIdx] = apply( st[segIdx], uval ); 
            lazy[segIdx] += uval; 
            propagate( segIdx, al, ar );  

            return;
        }
    
        /* parital overlap */
        
        int mid=( ar + al ) / 2;

        update( left(segIdx), al, mid, ul, ur, uval );
        update( right(segIdx), mid+1, ar, ul, ur, uval );
       
       st[segIdx] = merge( st[left(segIdx)], st[right(segIdx)] );
    }

};
