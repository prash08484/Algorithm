// Longest Palindromic Substring in O(n)
vector<int> manacher(string& str) {

    // transform string
    string s = "";
    for (char &it : str)
        s += "#" + string(1, it);
    s += "#";

    int n = s.size();
  
    // sentinels
    s = "$" + s + "^";

    vector<int> p(n + 2, 0);

    int l = 0, r = 0;

    for (int i = 1; i <= n; i++) {

        int j = l + r - i; // mirror index

        if (i < r) 
          p[i] = min(r - i, p[j]);

        // expand
        while (s[i - (p[i] + 1)] == s[i + (p[i] + 1)])
            p[i]++;

        // update best segment
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
  
    str=s;
    
  return p;
}
