
//  n nodes and m operation 
// T.C.  O(m*α(n)) : α is inverse-akerman func α(n)<=4 
class DSU{
public:
      vector<int> parent;
      vector<int> rank;

    DSU(int n){
        parent.resize(n);
        iota(begin(parent),end(parent),0);
        rank.resize(n,0);
    }

   int find(int x){
    if (x == parent[x])
        return x;
        
    // Path Compression 
    parent[x] = find(parent[x]); 
    return parent[x];
 }

  bool merge(int x,int y){ // union by rank
    int a = find(x);
    int b = find(y);
    if (a == b)
        return 0;

    if (rank[a] > rank[b]) {
        parent[b] = a; }
    else if (rank[a] < rank[b]){
        parent[a] = b; }
    else {
        parent[a] = b;
        rank[b]++; }
      return 1;
  }
};
