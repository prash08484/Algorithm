
// Netwton's Method T.C. 
ld nth_root(ll m, ll n) {
    if (n == 1) return (ld)m;
    if (m == 0)  return 0.0L;

    auto expo_ld=[](ld base,ld exp)->ld{
        ld  res = 1.0L;
        ll e = exp;
        while (e > 0) {
          if (e & 1) res *= base;
          base *= base;
          e >>= 1;  }
         return res;
    };

    bool neg = (m < 0);
    ld a = neg ? -(ld )m : (ld )m;
    
    // initial guess
    ld  x = expl(logl(a) / (ld )n);
    if (!(x > 0.0L) || !isfinite(x)) x = 1.0L;
    ld  rel_eps = 1e-9L; // precision    
  
    for (int iter = 0; iter < 20; ++iter) {
        ld  x_nm1 = expo_ld(x, n - 1); // expo
        // Newton update:  
        ld  x_next = ((n - 1.0L) * x + a / x_nm1) / (ld )n;
        ld  step = fabsl(x_next - x);
        if (step <= rel_eps * fabsl(x_next)) {
            x = x_next;
            break; }
        x = x_next;
    }
    return neg ? -x : x;
}

