
// Sum of Each subarrays max. or min
// T.C. O(n)

long long sumSubarrayMinMax(vector<int>& arr) {

    int n = size(arr);

    stack<pair<int, long long>> st;
    
    long long ans = 0;
    int mn = 0;

    for (int i = 0; i < n; i++) {
        int val = arr[i];
        
        // For maxs val>=arr[st.top().first]
        // For mins val<=arr[st.top().first]
        
        // UPDATE NEEDED 
        while (!st.empty() and val <= arr[st.top().first]) {
            st.pop();
        }
        if (st.empty()) {
            long long temp = val * (i + 1LL);
            ans += temp;
            st.push({i, temp});
        } 
        else {
            auto [idx, prefSum] = st.top();
            long long temp = (i - idx * 1LL) * val + prefSum;
            ans += temp;
            st.push({i, temp});
        }
    }
    return ans;
}
