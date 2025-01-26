void solve()
{
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size(); 
    if (tlen > slen)
    {
        cout << 0 << endl;
        return;
    }
    int p = 31, ph = 1;
    int power = 0; // for tlen
    int Power = 0; // for slen
    for (int i = 0; i < tlen; i++)
    { 
        char it = t[i];
        power = (power*p+(it-'a'+1)) % mod; 
        it = s[i];
        Power = (Power*p+(it - 'a' + 1)) % mod;
        if (i < (tlen-1))
        {
            ph = ph * p;
            ph %= mod;
        }
    }
    int count = 0;
    // cout<<Power<<"  "<<power<<endl;
    if (power == Power)
        count++;
    for (int i = tlen; i < slen; i++)
    {
        char it = s[i-tlen];
        Power = (Power-(it - 'a' + 1) * ph % mod + mod) % mod; // handling -ve and  remove contribution of extra character
        it = s[i];
        Power*=p; 
        Power += (it - 'a' + 1);
        Power %= mod;
        if (power == Power)
            count++;
    }
 
    cout << count << endl;
    return;
}
