class Mo {
public:
    using Query = pair<pair<ll,ll>, ll>; // {{l, r}, idx}

    ll n, q;
    ll BLOCK;

    vector<ll>a; // input array  
    vector<ll>ans;
    vector<Query>qry;

    ll currSum = 0;

    Mo(vector<ll>& arr, vector<pair<ll,ll>>& queriesInput){
        n = arr.size();
        q = queriesInput.size();

        a = arr;
        qry.resize(q);

        for (ll i=0; i<q; i++) {
            ll l = queriesInput[i].first - 1; // 0-based
            ll r = queriesInput[i].second - 1;
            qry[i] = {{l, r}, i};
        }
        ans.assign(q, 0);
    } 

    void add(ll pos) { 
        currSum += a[pos];
    }

    void remove(ll pos) { 
        currSum -= a[pos];
    } 

    void run(){
        BLOCK = sqrt(n);

        sort(qry.begin(), qry.end(),[this](const Query& a1, const Query& a2){
                ll blockA = a1.first.first / BLOCK;
                ll blockB = a2.first.first / BLOCK;
                if (blockA != blockB){
                    return blockA < blockB;
                }
                return (blockA&1) ? (a1.first.second>a2.first.second) : (a1.first.second<a2.first.second);
            });

        ll L = 0, R = -1;
        for (auto &qv : qry) {
            ll l = qv.first.first;
            ll r = qv.first.second;
            ll idx = qv.second;

            while(L>l)add(--L);
            while(R<r)add(++R);
            while(L<l)remove(L++);
            while(R>r)remove(R--);

            ans[idx] = currSum;
        }
    }
};
