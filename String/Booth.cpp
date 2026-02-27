
// Lexo smallest roatate array where T.C : O(n) 
vector<ll> smallest_rotation(vector<ll>& a) {
    int n = a.size();
    if (n<=1) return a;

    vector<ll> b(2*n);
    for (int i=0; i<2*n; i++) b[i] = a[i%n];

    int i=0, j=1, k=0;
    while (i<n && j<n && k<n) {
        if (b[i+k] == b[j+k]) {
            k++;
        } 
        else if (b[i+k] < b[j+k]) {
            j = j+k+1;
            if (i==j) j++;
            k=0;
        } 
        else {
            i = i+k+1;
            if (i == j) i++;
            k = 0;
        }
    }

    int start = min(i,j);
    vector<ll> res(n);
    for (int i=0; i<n; i++){ 
        res[i] = a[(start+i)%n];
    }
    return res;
}
