// Longest Palindromic Substring
// T.C: O(n)
vector<int> manacher(string& str) {

    // transform string
    string s = "";
    for (char &it : str)
        s += "#" + string(1, it);
    s += "#";
    s = "$" + s + "^";

    int n = s.size();
    vector<int> p(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n-1; i++) {

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

    /*
     To get the original indices :
       int left=i-p[i]+1; // remove last # by adding 1
       int right=i-p[i]-1; // remove last # by substracting 1 
       left=(left-2)/2; // OG Indices 
       right=(right-2)/2; // OG Indices 
    */
    
  return p;
}
