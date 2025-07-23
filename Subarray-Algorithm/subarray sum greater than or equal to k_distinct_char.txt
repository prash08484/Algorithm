  int func(string &str, int k) {
    int n = str.size();
    if (k > n) {
        return 0; // No substrings with at least k distinct characters
    }

    vector<int> f(26, 0); // freq.
    int j = 0;
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (f[str[i] - 'a'] == 0) {
            cnt++;  }
        f[str[i] - 'a']++;

        while (cnt >= k) {
            ans += (n - i); // All substrings starting from 'j' to 'i' and ending at any position after 'i'
            
            f[str[j] - 'a']--;
            if (f[str[j] - 'a'] == 0) {
                cnt--;
            }
            j++;
        }
    }

    return ans;
}
