int min_swap_sort(const vector<int>& idx) {
    int n = idx.size();
    vector<bool> vis(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] || idx[i] == i) continue;

        int cycle = 0, j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = idx[j];
            cycle++;
        }
        swaps += cycle - 1;
    }
    return swaps;
}
