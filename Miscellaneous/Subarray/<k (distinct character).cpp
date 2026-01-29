// number of subarray of a have < k distinct character 
ll Kless(auto &a, ll k) {  
    if(k==0) return 0;
    ll ans = 0, len = 0, j = 0;
    map<ll, ll> mpp;
    for (auto &it : a) {
        mpp[it]++;
        len++;
        while (mpp.size() == k){
            mpp[a[j]]--;
            if (mpp[a[j]] == 0) {
                mpp.erase(a[j]);
            }
            j++;
            len--;
        }
        ans += len;
    }
    return ans;
}
