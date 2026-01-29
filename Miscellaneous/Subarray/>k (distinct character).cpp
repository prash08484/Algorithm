// number of subarray of a have > k distinct character 
ll Kmore(auto &a, ll k) {
    ll n = a.size();
    if(k >= n) return 0; 

    map<ll, ll> freq;
    ll ans = 0, j = 0;

    for (ll i = 0; i < n; i++) {
        freq[a[i]]++;
 
        while(freq.size() > k) {
            freq[a[j]]--;
            if(freq[a[j]] == 0){
                freq.erase(a[j]);
            }
            j++;
        }
        // Number of subarrays ending at i with > k distinct = j
        ans += j;
    }
    return ans;
}

