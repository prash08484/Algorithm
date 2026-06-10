// T.C. : 
// O(nlogn) build
// O(1) for idempotent 
// O(logN) for general 

template<typename Node>
struct SparseTable {
    
    // Prerequisite
    vector<int> logValues;
    int maxLog;
    
    // DATA REQ. 
    int n; 
    vector<int> arr;
    vector<vector<Node>> table;

    SparseTable(vector<int> &arr) {

        n = size(arr);
        this->arr = arr;
        table.resize(n);
        logValues.resize(n + 1);
        maxLog = log2(n);
        logValues[1] = 0;

        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            table[i].resize(maxLog + 1);
            fill(begin(table[i]), end(table[i]), Node());
        }

        build();
    }

    void build() {

        for (int i = 0; i < n; i++) {
            table[i][0] = Node(arr[i]);
        }

        for (int i = 1; i <= maxLog; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }

    }
    

    // Query Idempotent
    Node query(int left, int right) {
        int j = logValues[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
    
    // Query Normal
    Node queryNormal(int left, int right) {
        Node ans = Node();
        for (int j = logValues[right - left + 1]; j >= 0; j--) {
            if ((1 << j) <= right - left + 1) {
                ans.merge(ans, table[left][j]);
                left += (1 << j);
            }
        }
        return ans;
    }

};

struct Node1 {
    
    // DATA PER NODE : store more info if required
    ll val; 

    Node1() { // Identity Element
        val = 0;
    }

    Node1(ll v) { 
        val = v;
    }

    void merge(Node1 &l, Node1 &r) {
        val = l.val ^ r.val;
    }

};

/*
e.g.
SparseTable<Node1> st(arr); 
st.queryIdemopotent(l,r).val 
*/
