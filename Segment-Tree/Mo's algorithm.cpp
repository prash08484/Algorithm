// T.C. O((n + q) * sqrt(n))
class Mo {
public: 
    struct Query { ll L,R,idx; };

    ll n, q;
    ll BLOCK;

    vector<ll>arr; // Input Array  
    vector<ll>ans; 
    vector<Query>qry;

    ll currSum = 0; // UPDATE AS REQ

    Mo(vector<ll>& inputArray, vector<pair<ll,ll>>& queriesInput){
        arr = inputArray;
        n = arr.size();
        q = queriesInput.size(); // 0-based
 
        qry.resize(q);

        for (ll i=0; i<q; i++) {
            qry[i].L = queriesInput[i].L; 
            qry[i].R = queriesInput[i].R; 
            qry[i].idx = i;
        }
        ans.assign(q, 0);
        run();
    } 

    void add(ll pos) { 
        currSum += arr[pos]; // UPDATE REQ.
    }

    void remove(ll pos) { 
        currSum -= arr[pos]; // UPDATE REQ. 
    } 

    void run(){
        BLOCK = sqrt(n);

        sort(begin(qry), end(qry), [this](const Query& a1, const Query& a2){
                ll blockA = a1.L / BLOCK;
                ll blockB = a2.L / BLOCK;
                if (blockA != blockB){
                    return blockA < blockB;
                }
                return (blockA&1) ? (a1.L > a2.L) : (a1.R < a2.R);
            });

        ll L = 0, R = -1;
        for (auto &qv : qry) {
            ll l = qv.L;
            ll r = qv.R;
            ll idx = qv.idx;

            while(L>l)add(--L);
            while(R<r)add(++R);
            while(L<l)remove(L++);
            while(R>r)remove(R--);

            ans[idx] = currSum;
        }
    }
};
