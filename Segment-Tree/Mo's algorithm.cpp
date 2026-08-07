// Sorting : O(Q log Q)
// Processing : O((N + Q) * sqrt(N))

class Mo {
public: 
    struct Query { int L,R,idx; };

    int n, q;
    int BLOCK;
    
    // Input Data 
    vector<int>arr;   // element array  
    vector<Query>qry; // query array 
    
    // Answer Array
    vector<int>ans; 

    // Data Per Block 
    long long currSum = 0; // UPDATE REQ. 


    Mo(vector<int>& inputArray, vector<pair<int,int>>& queriesInput){
        arr = inputArray;
        n = arr.size();
        q = queriesInput.size(); // 0-based
 
        qry.resize(q);

        for (int i=0; i<q; i++) {
            qry[i].L = queriesInput[i].first; 
            qry[i].R = queriesInput[i].second; 
            qry[i].idx = i;
        }
        ans.assign(q, 0);
        run();
    } 

    void add(int pos) { 
        currSum += arr[pos]; // UPDATE REQ.
    }

    void remove(int pos) { 
        currSum -= arr[pos]; // UPDATE REQ. 
    } 

    void run(){

        // BLOCK = sqrt(n);  
        BLOCK = max(1, (int)(n / sqrt(q)));  // Performence Q >>> N

        sort(begin(qry), end(qry), [this](const Query& a1, const Query& a2){
                int blockA = a1.L / BLOCK;
                int blockB = a2.L / BLOCK;
                if (blockA != blockB){
                    return blockA < blockB;
                }
                return (blockA&1) ? (a1.R > a2.R) : (a1.R < a2.R);
            });

        int L = 0, R = -1;
        for (auto &qv : qry) {
            int l = qv.L;
            int r = qv.R;
            int idx = qv.idx;

            while(L>l)add(--L);
            while(R<r)add(++R);
            while(L<l)remove(L++);
            while(R>r)remove(R--);

            ans[idx] = currSum;
        }
    }
};

