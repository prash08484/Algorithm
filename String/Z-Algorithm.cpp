// T.C. O(n) 

vector<int> computeZArray(const string& s) {
    int n = s.size();
    vector<int> z(n,0); // z[i]: store max len of mathcing prefix starting at index i
    int left=0, right=0;

    // left-right store rightmost window that matches
    // s[0.....(right-left+1)] == s[left....right]

    for (int i=1; i<n; i++) {
        if (i <= right){
            z[i] = min(right-i+1, z[i-left]);
        }
        // Expand the Z-box by matching characters
        while ((i+z[i]<n) && s[z[i]]==s[i+z[i]]){
            z[i]++;
       }
        // Update the window if we expanded beyond right
        if( (i+z[i]-1) > right) {
            left = i;
            right = i+z[i]-1;
        }
    }
    return z;
}

vector<int> zFunction(const string& text, const string& pattern) { 
    string combined = pattern + "$" + text; 
    vector<int> z = computeZArray(combined);
    vector<int> result;

    for (int i = pattern.size()+1; i<combined.size(); i++) {
        if (z[i] == pattern.size()) {
           // when len == pattern.size() that's match
            result.push_back(i-pattern.size()-1);
        }
    }
    return result;
}
